/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:52:13 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/22 18:21:56 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	size_t	len;

	nbr = (long)n;
	len = int_len(nbr);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		res [0] = '0';
	while (nbr > 0)
	{
		res[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (res);
}
/*
int main(void) {
    int num1 = 12345;
    int num2 = -9876;
    int num3 = 0;

    char *str1 = ft_itoa(num1);
    char *str2 = ft_itoa(num2);
    char *str3 = ft_itoa(num3);

    printf("Integer: %d, String: %s\n", num1, str1);
    printf("Integer: %d, String: %s\n", num2, str2);
    printf("Integer: %d, String: %s\n", num3, str3);

    // Free allocated memory
    free(str1);
    free(str2);
    free(str3);

    return 0;
}*/