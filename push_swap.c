/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:56:36 by joafern2          #+#    #+#             */
/*   Updated: 2024/10/08 19:48:50 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_stacks(int *a, int *b, int a_size, int b_size)
{
	int	i;
	char	*ascii;

	write(1, "Stack a:\n", 9);
	i = 0;
	while (i < a_size)
	{
		ascii = ft_itoa(a[i]);
		write(1, ascii, ft_strlen(ascii));
		write(1, "\n", 1);
		free(ascii);
		i++;
	}
	write(1, "Stack b:\n", 9);
	i = 0;
	while (i < b_size)
	{
		ascii = ft_itoa(b[i]);
		write(1, ascii, ft_strlen(ascii));
		write(1, "\n", 1);
		free(ascii);
		i++;
	}
}

void	swap_a(int *a)
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write(1, "sa\n", 3);
}

void	push_a(int *a, int *b, int *a_size, int *b_size)
{
	int	i;

	i = *a_size;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	(*a_size)++;
	a[0] = b[0];
	i = 0;
	while (i + 1 < *b_size)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*b_size)--;
	write(1, "pa\n", 3);
}

void	push_b(int *a, int *b, int *a_size, int *b_size)
{
	int	i;

	i = *b_size;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	(*b_size)++;
	i = 0;
	while (i + 1 < *a_size)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*a_size)--;
	write(1, "pb\n", 3);
}
