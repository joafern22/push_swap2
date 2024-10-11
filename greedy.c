/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:54:25 by joafern2          #+#    #+#             */
/*   Updated: 2024/10/09 20:54:41 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy_insertion(t_stacks *stacks)
{
	t_cheapest_moves	*cheapest;
	int	correct_position;

	cheapest = malloc(sizeof(t_cheapest_moves));
	if (!cheapest)
	{
		write(1, "Error\n", 6);
		return ;
	}	
	push_b(stacks->a, stacks->b, &stacks->a_size, &stacks->b_size);
	push_b(stacks->a, stacks->b, &stacks->a_size, &stacks->b_size);
	while (stacks->a_size > 3)
	{
		calculate_best_moves(stacks, cheapest);
		execute_best_moves(stacks, cheapest);
		push_b(stacks->a, stacks->b, &stacks->a_size, &stacks->b_size);
	}
	free(cheapest);
	sort_three(stacks->a, stacks->a_size);
	while (stacks->b_size > 0)
	{
		correct_position = find_a_target_position(stacks->a, stacks->a_size, stacks->b[0]);
		prepare_a(stacks->a, stacks->a_size, correct_position);
		push_a(stacks->a, stacks->b, &stacks->a_size, &stacks->b_size);
	}
	prepare_a(stacks->a, stacks->a_size, find_min_index(stacks->a, stacks->a_size));
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
