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
#include <stdio.h>

/* TO DO:
 * Check for non-numerical values;
 * Check for argv > INT_MAX || argv < INT_MIN;
 * Check for error memory leaks;
 * Check again! :)
*/

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	a = NULL;
	b = NULL;
	a_size = argc - 1;
	b_size = 0;
	if (!allocate_stacks(&a, &b, a_size))
		return (EXIT_FAILURE);
	if (!parser(a, b, a_size, argv))
	{
		free(a);
		free(b);
		return (EXIT_FAILURE);
	}
	if (!edge_cases(a, a_size))
		greedy_insertion(a, b, &a_size, &b_size);
	//write_stacks(a, b, a_size, b_size);
	free(a);
	free(b);
	return (0);
}

int	allocate_stacks(int **a, int **b, int a_size)
{
	*a = malloc((a_size) * sizeof(int));
	if (!(*a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	*b = malloc((a_size) * sizeof(int));
	if (!(*b))
	{
		free(a); 
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	parser(int *a, int *b, int a_size, char **argv)
{
	int	i;

	i = 0;
	(void)b;
	while (i < a_size)
	{
		a[i] = ft_atoi(argv[i + 1]);
		if (is_duplicate(a[i], a, i) || a[i] < INT_MIN || a[i] > INT_MAX)
		{
			write(2, "Error\n", 6);
			//printf("%d\n", a[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

// Check if argc == 2 || argc == 3 || argc == 4;
// Check if the list is already sorted;

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
