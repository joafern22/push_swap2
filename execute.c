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

void	execute_best_moves(int *a, int *b, int a_size, int b_size,  cheapest_moves *cheapest)
{
	int	combination;

	combination = best_combination(
		(cheapest->cheapest_ra + cheapest->cheapest_rb + cheapest->cheapest_rr),
		(cheapest->cheapest_rra + cheapest->cheapest_rrb + cheapest->cheapest_rrr),
		cheapest->cheapest_ra_rrb, cheapest->cheapest_rb_rra);
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
