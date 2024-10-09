/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:54:25 by joafern2          #+#    #+#             */
/*   Updated: 2024/10/09 20:54:55 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	calculate_best_moves(int *a, int *b, int a_size, int b_size, cheapest_moves *cheapest)
{
	int	i;
	record_moves	current_moves;

	i = 0;
	cheapest->cheapest_move_count = INT_MAX;
	while (i < a_size)
	{
		current_moves.target_b_index = find_b_target_position(b, b_size, a[i]);
		calculate_moves(a_size, b_size, i, &current_moves);
		if (current_moves.total_moves < cheapest->cheapest_move_count)
			update_cheapest(cheapest, &current_moves, i);
		i++;
	}
}

void	update_cheapest(cheapest_moves *cheapest, record_moves *current_moves, int i)
{
	cheapest->cheapest_move_count = current_moves->total_moves;
	cheapest->cheapest_ra = current_moves->ra_moves;
	cheapest->cheapest_rb = current_moves->rb_moves;
	cheapest->cheapest_rra = current_moves->rra_moves;
	cheapest->cheapest_rrb = current_moves->rrb_moves;
	cheapest->cheapest_rr = current_moves->rr_moves;
	cheapest->cheapest_rrr = current_moves->rrr_moves;
	cheapest->cheapest_ra_rrb = current_moves->ra_rrb_moves;
	cheapest->cheapest_rb_rra = current_moves->rb_rra_moves;
	cheapest->cheapest_a_index = i;
}
	
	
void	calculate_moves(int a_size, int b_size, int a_index, record_moves *moves)
{
	int	b_index;

	b_index = moves->target_b_index;
	moves->ra_moves = a_index;
	moves->rra_moves = a_size - a_index;
	moves->rb_moves = b_index;
	moves->rrb_moves = b_size - b_index;
	moves->ra_rrb_moves = moves->ra_moves + moves->rrb_moves;
	moves->rb_rra_moves = moves->rb_moves + moves->rra_moves;
	moves->rr_moves = min(moves->ra_moves, moves->rb_moves);
	moves->rrr_moves = min(moves->rra_moves, moves->rrb_moves);
	calculate_total_moves(moves);
}

void	calculate_total_moves(record_moves *moves)
{
	moves->ra_moves -= moves->rr_moves;
	moves->rb_moves -= moves->rr_moves;
	moves->rra_moves -= moves->rrr_moves;
	moves->rrb_moves -= moves->rrr_moves;
	moves->total_moves = min(moves->ra_rrb_moves, moves->rb_rra_moves);
	moves->total_moves = min(moves->total_moves,
		(moves->ra_moves + moves->rb_moves + moves->rr_moves));
	moves->total_moves = min(moves->total_moves,
		(moves->rra_moves + moves->rrb_moves + moves->rrr_moves));
}

void	execute_best_moves(int *a, int *b, int a_size, int b_size,  cheapest_moves *cheapest)
{
	int	combination;

	/*printf("ra: %d, rb: %d, rra: %d, rrb: %d\n", cheapest->cheapest_ra, cheapest->cheapest_rb, cheapest->cheapest_rra, cheapest->cheapest_rrb);
	fflush(stdout);
    	printf("ra+rrb: %d, rb+rra: %d, rr: %d, rrr: %d\n",  cheapest->cheapest_ra_rrb, cheapest->cheapest_rb_rra, cheapest->cheapest_rr, cheapest->cheapest_rrr);
	fflush(stdout);*/
	combination = best_combination(
		(cheapest->cheapest_ra + cheapest->cheapest_rb + cheapest->cheapest_rr),
		(cheapest->cheapest_rra + cheapest->cheapest_rrb + cheapest->cheapest_rrr),
		cheapest->cheapest_ra_rrb, cheapest->cheapest_rb_rra);
	//printf("combination = %d\n", combination);
	fflush(stdout);
	if (combination == 1)
		execute_rotation(a, b, a_size, b_size, cheapest);
	else if (combination == 2)
		execute_reverse_rotation(a, b, a_size, b_size, cheapest);
	else if (combination == 3)
		execute_ra_rrb(a, b, a_size, b_size, cheapest);
	else
		execute_rb_rra(a, b, a_size, b_size, cheapest);
}

int	best_combination(int one, int two, int three, int four)
{
	int	min;
	int	combination;

	min = one;
	combination = 1;
	if (two < min)
	{
		min = two;
		combination = 2;
	}
	if (three < min)
	{
		min = three;
		combination = 3;
	}
	if (four < min)
		combination = 4;
	return (combination);
}
	

void	execute_ra_rrb(int *a, int *b, int a_size, int b_size, cheapest_moves *cheapest)
{
	cheapest->cheapest_ra += cheapest->cheapest_rr;
	cheapest->cheapest_rrb += cheapest->cheapest_rrr;
	while (cheapest->cheapest_ra > 0)
	{
		rotate_a(a, &a_size);
		cheapest->cheapest_ra--;
	}
	while (cheapest->cheapest_rrb > 0)
	{
		r_rotate_b(b, &b_size);
		cheapest->cheapest_rrb--;
	}
}

void	execute_rb_rra(int *a, int *b, int a_size, int b_size,cheapest_moves *cheapest)
{
	cheapest->cheapest_rb += cheapest->cheapest_rr;
	cheapest->cheapest_rra += cheapest->cheapest_rrr;
	while (cheapest->cheapest_rb > 0)
	{
		rotate_b(b, &b_size);
		cheapest->cheapest_rb--;
	}
	while (cheapest->cheapest_rra > 0)
	{
		r_rotate_a(a, &a_size);
		cheapest->cheapest_rra--;
	}
}	

void	execute_rotation(int *a, int *b, int a_size, int b_size, cheapest_moves *cheapest)
{
	while (cheapest->cheapest_rr > 0)
	{
		rotate_rr(a, b, &a_size, &b_size);
		cheapest->cheapest_rr--;
	}
	while (cheapest->cheapest_ra > 0)
	{
		rotate_a(a, &a_size);
		cheapest->cheapest_ra--;
	}
	while (cheapest->cheapest_rb > 0)
	{
		rotate_b(b, &b_size);
		cheapest->cheapest_rb--;
	}
}

void	execute_reverse_rotation(int *a, int *b, int a_size, int b_size, cheapest_moves *cheapest)
{
	while (cheapest->cheapest_rrr > 0)
	{
		r_rotate_rr(a, b, &a_size, &b_size);
		cheapest->cheapest_rrr--;
	}
	while (cheapest->cheapest_rra > 0)
	{
		r_rotate_a(a, &a_size);
		cheapest->cheapest_rra--;
	}
	while (cheapest->cheapest_rrb > 0)
	{
		r_rotate_b(b, &b_size);
		cheapest->cheapest_rrb--;
	}
}

