/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:12:15 by mvann             #+#    #+#             */
/*   Updated: 2017/09/19 16:07:24 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;
	int len;

	len = ft_strlen(src);
	i = 0;
	while (i < len + 1)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
