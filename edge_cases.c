/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:56:36 by joafern2          #+#    #+#             */
/*   Updated: 2024/10/09 21:19:50 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if argc == 2 || argc == 3 || argc == 4;
// Check if the list is already sorted;

int	edge_cases(int *a, int a_size)
{
	if (sorted(a, a_size))
		return (1);
	else if (a_size == 2)
	{
		sort_two(a, a_size);
		return (1);
	}
	else if (a_size == 3)
	{
		sort_three(a, a_size);
		return (1);
	}
	else
		return (0);
}

int	sorted(int *a, int a_size)
{
	int	i;

	i = 0;
	if (a_size == 1)
		return (1);
	while (i < a_size - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_two(int *a, int a_size)
{
	if (a_size != 2)
		return ;
	if (a[0] > a[1])
		swap_a(a);
}

void	sort_three(int *a, int a_size)
{
	if (a_size != 3)
		return ;
	if (a[0] > a[1] && a[0] > a[2])
		rotate_a(a, &a_size);
	else if (a[1] > a[0] && a[1] > a[2])
		r_rotate_a(a, &a_size);
	if (a[0] > a[1])
		swap_a(a);
}
