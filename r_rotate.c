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

void	r_rotate_a(int *a, int *a_size)
{
	int	temp;
	int	i;

	i = *a_size - 1;
	temp = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	write(1, "rra\n", 4);
}

void	r_rotate_b(int *b, int *b_size)
{
	int	temp;
	int	i;

	i = *b_size - 1;
	temp = b[i];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write(1, "rrb\n", 4);
}

void	r_rotate_rr(int *a, int *b, int *a_size, int *b_size)
{
	int	temp;
	int	i;

	i = *a_size - 1;
	temp = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	i = *b_size - 1;
	temp = b[i];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write(1, "rrr\n", 4);
}
