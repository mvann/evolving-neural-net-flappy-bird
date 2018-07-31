/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 20:12:32 by mvann             #+#    #+#             */
/*   Updated: 2017/09/21 16:23:51 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (s)
	{
		s2 = (char *)malloc(len + 1);
		if (!s2)
			return (s2);
		i = 0;
		while (i < len && s[start + i])
		{
			s2[i] = s[start + i];
			i++;
		}
		s2[i] = 0;
		return (s2);
	}
	return (NULL);
}
