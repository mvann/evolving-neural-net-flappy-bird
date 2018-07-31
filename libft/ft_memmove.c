/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:34:23 by mvann             #+#    #+#             */
/*   Updated: 2017/09/19 18:20:56 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (dst - src > 0)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char*)dst)[len - i - 1] =
			((unsigned char*)src)[len - i - 1];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dst);
}
