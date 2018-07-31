/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:48:24 by mvann             #+#    #+#             */
/*   Updated: 2017/09/26 18:59:26 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	sum;
	int				i;
	int				negative;
	unsigned long	long_max;

	long_max = 9223372036854775807;
	i = 0;
	sum = 0;
	negative = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		negative = str[i++] == '-';
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		if (!negative && sum > long_max)
			return (-1);
		else if (negative && sum > long_max + 1)
			return (0);
		i++;
	}
	return ((int)sum * (negative ? -1 : 1));
}
