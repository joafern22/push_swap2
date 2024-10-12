/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sort_prepare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:54:25 by joafern2          #+#    #+#             */
/*   Updated: 2024/10/09 20:54:09 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_a(int *a, int a_size, int position)
{
	if (position <= a_size / 2)
	{
		while (position > 0)
		{
			rotate_a(a, &a_size);
			position--;
		}
	}
	else
	{
		while (position < a_size)
		{
			r_rotate_a(a, &a_size);
			position++;
		}
	}
}

int	find_a_target_position(int *stack, int stack_size, int nbr)
{
	int	i;
	int	target_index;

	i = 0;
	target_index = -1;
	while (i < stack_size)
	{
		if (stack[i] > nbr)
		{
			if (target_index == -1 || (stack[i] < stack[target_index]))
			{
				target_index = i;
			}
		}
		i++;
	}
	if (target_index == -1)
		target_index = (find_max_index(stack, stack_size) + 1) % stack_size;
	return (target_index);
}

int	find_b_target_position(int *stack, int stack_size, int nbr)
{
	int	i;
	int	target_index;

	i = 0;
	target_index = -1;
	while (i < stack_size)
	{
		if (stack[i] < nbr)
		{
			if (target_index == -1 || (stack[i] > stack[target_index]))
			{
				target_index = i;
			}
		}
		i++;
	}
	if (target_index == -1)
		target_index = (find_min_index(stack, stack_size) + 1)
			% stack_size;
	return (target_index);
}

int	find_min_index(int *a, int a_size)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = 0;
	while (i < a_size)
	{
		if (a[i] < a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	find_max_index(int *b, int b_size)
{
	int	i;
	int	max_index;

	i = 0;
	max_index = 0;
	while (i < b_size)
	{
		if (b[i] > b[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}
