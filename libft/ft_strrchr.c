/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:05:58 by mvann             #+#    #+#             */
/*   Updated: 2017/09/26 18:19:59 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;

	len = ft_strlen(s);
	i = len;
	while (i >= 0)
	{
		if (s[i] == c)
			return (char *)s + i;
		i--;
	}
	return (NULL);
}
