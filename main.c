/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:56:36 by joafern2          #+#    #+#             */
/*   Updated: 2024/10/04 21:20:10 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;

	if (argc < 2)
	{
		write(2, "Error argument number\n", 6);
		return (EXIT_FAILURE);
	}
	a = NULL;
	b = NULL;
	a_size = argc - 1;
	b_size = 0;
	if (allocate_stacks(&a, &b, a_size))
		return (EXIT_FAILURE);
	if (parser(a, b, a_size, argv))
		return (EXIT_FAILURE);
	greedy_insertion(a, b, &a_size, &b_size);
	write_stacks(a, b, a_size, b_size);
	return (0);
}

int	allocate_stacks(int **a, int **b, int a_size)
{
	*a = malloc((a_size) * sizeof(int));
	if (!(*a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	*b = malloc((a_size) * sizeof(int));
	if (!(*b))
	{
		free(a);
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	parser(int *a, int *b, int a_size, char **argv)
{
	int	i;

	i = 0;
	(void)b;
	while (i < a_size)
	{
		a[i] = ft_atoi(argv[i + 1]);
		if (is_duplicate(a[i], a, i) || ft_isdigit(a[i]))
		{
			free(a);
			free(b);
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
