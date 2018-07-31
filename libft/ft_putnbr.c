/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:01:23 by mvann             #+#    #+#             */
/*   Updated: 2017/09/26 18:34:08 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		negative;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		negative = (n < 0);
		if (negative)
		{
			n *= -1;
			ft_putchar('-');
		}
		if (n >= 0 && n <= 9)
			ft_putchar(n + '0');
		else
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
}
