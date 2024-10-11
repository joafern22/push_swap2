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
 * Check for error memory leaks;
 * Check again! :)
*/

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stacks = init_stacks(argc);
	if (!stacks)
		return (0);
	if (!allocate_stacks(&stacks->a, &stacks->b, stacks->a_size))
	{
		free(stacks);
		return (0);
	}
	if (parser(stacks->a, stacks->b, stacks->a_size, argv))
	{	
		if (!edge_cases(stacks->a, stacks->a_size))
			greedy_insertion(stacks);
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}

t_stacks	*init_stacks(int argc)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->a_size = argc - 1;
	stacks->b_size = 0;
	return (stacks);
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
	int	error;

	i = 0;
	error = 0;
	(void)b;
	while (i < a_size)
	{
		a[i] = ft_atoi(argv[i + 1], &error);
		if (is_duplicate(a[i], a, i) ||!ft_isdecimal(argv[i + 1]) || error)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
