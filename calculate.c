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

void	calculate_best_moves(t_stacks *stacks, t_cheapest_moves *cheapest)
{
	int				i;
	t_record_moves	current_moves;

	i = 0;
	cheapest->cheapest_move_count = INT_MAX;
	while (i < stacks->a_size)
	{
		current_moves.target_b_index = find_b_target_position(stacks->b,
				stacks->b_size, stacks->a[i]);
		calculate_moves(stacks->a_size, stacks->b_size, i, &current_moves);
		if (current_moves.total_moves < cheapest->cheapest_move_count)
			update_cheapest(cheapest, &current_moves, i);
		i++;
	}
}

void	calculate_moves(int a_size, int b_size, int a_index,
		t_record_moves *moves)
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

void	calculate_total_moves(t_record_moves *moves)
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

void	update_cheapest(t_cheapest_moves *cheapest,
		t_record_moves *current_moves, int i)
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
