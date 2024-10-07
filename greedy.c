/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_instertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:54:25 by joafern2          #+#    #+#             */
/*   Updated: 2024/10/04 21:28:06 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy_insertion(int *a, int *b, int *a_size, int *b_size)
{
	int	correct_position;
	cheapest_moves	cheapest;
	
	push_b(a, b, a_size, b_size);
	push_b(a, b, a_size, b_size);
	while (*a_size > 3)
	{
		calculate_best_moves(a, b, *a_size, *b_size, &cheapest);
		execute_best_moves(a, b, *a_size, *b_size, &cheapest);
		push_b(a, b, a_size, b_size);
	}
	sort_three(a, *a_size);
	while (*b_size > 0)
	{
		correct_position = find_target_position(a, *a_size, b[0]);
		prepare_a(a, *a_size, correct_position);
		push_a(a, b, a_size, b_size);
	}
	prepare_a(a, *a_size, find_min_index(a, *a_size));
}

int	max(int	moves1, int moves2)
{
	if (moves1 > moves2)
		return (moves1);
	else
		return (moves2);
}

int	min(int moves1, int moves2)
{
	if (moves1 < moves2)
		return (moves1);
	else
		return (moves2);
}
