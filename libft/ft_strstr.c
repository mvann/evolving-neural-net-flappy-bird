/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:46:56 by mvann             #+#    #+#             */
/*   Updated: 2017/09/20 20:56:54 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
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
	i = -1;
	while (++i + little_len <= big_len)
	{
		found = 1;
		j = 0;
		while (j < little_len)
		{
			if (big[i + j] != little[j])
				found = 0;
			j++;
		}
		if (found)
			return ((char *)big + i);
	}
	return (NULL);
}
