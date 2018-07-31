/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:43:35 by mvann             #+#    #+#             */
/*   Updated: 2017/09/19 15:44:56 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(size);
	if (str == NULL)
		return (str);
	i = 0;
	while (i < size)
		str[i++] = 0;
	return ((void *)str);
}
