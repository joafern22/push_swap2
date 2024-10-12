/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:23:13 by joafern2          #+#    #+#             */
/*   Updated: 2024/09/25 18:42:51 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr, int *error)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i])
	{
		if (sign > 0)
			res = res * 10 + (nptr[i] - '0');
		else
			res = res * 10 - (nptr[i] - '0');
		if ((sign > 0 && res > INT_MAX) || (sign < 0 && res < INT_MIN))
			*error = 1;
		i++;
	}
	return (res);
}
