/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:12:23 by mvann             #+#    #+#             */
/*   Updated: 2017/09/20 20:59:46 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;
	int found;
	int little_len;
	int big_len;

	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while ((size_t)(i + little_len) <= len && i + little_len <= big_len)
	{
		found = 1;
		j = -1;
		while (++j < little_len)
			if (big[i + j] != little[j])
				found = 0;
		if (found)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
