/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:41:10 by mvann             #+#    #+#             */
/*   Updated: 2017/09/26 18:12:27 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_length(int n)
{
	if (n >= -9 && n <= 9)
		return (1);
	return (1 + get_num_length(n / 10));
}

static int	test_int_min(int n, char *ascii)
{
	int		i;
	char	*min;

	min = "-2147483648";
	if (n == -2147483648)
	{
		i = -1;
		while (min[++i])
			ascii[i] = min[i];
		return (1);
	}
	return (0);
}

char		*ft_itoa(int n)
{
	int		i;
	int		len;
	int		neg;
	char	*ascii;

	len = get_num_length(n);
	neg = n < 0;
	if (!(ascii = (char *)malloc(len + neg + 1)))
		return (NULL);
	if (test_int_min(n, ascii))
		return (ascii);
	if (neg)
	{
		ascii[0] = '-';
		n *= -1;
	}
	i = 0;
	while (i < len)
	{
		ascii[(len + neg) - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	ascii[len + neg] = 0;
	return (ascii);
}
