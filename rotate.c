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

void	rotate_a(int *a, int *a_size)
{
	int	temp;
	int	i;

	i = 0;
	temp = a[0];
	while (i + 1 < *a_size)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(int *b, int *b_size)
{
	int	temp;
	int	i;

	i = 0;
	temp = b[0];
	while (i + 1 < *b_size)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = temp;
	write(1, "rb\n", 3);
}

void	rotate_rr(int *a, int *b, int *a_size, int *b_size)
{
	int	temp;
	int	i;

	i = 0;
	temp = a[0];
	while (i + 1 < *a_size)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = temp;
	i = 0;
	temp = b[0];
	while (i + 1 > *b_size)
	{			
		b[i] = b[i + 1];
		i++;
	}
	b[i] = temp;
	write(1, "rr\n", 3);
}
