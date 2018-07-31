/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:08:37 by mvann             #+#    #+#             */
/*   Updated: 2017/09/21 16:21:21 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*s2;

	if (s && f)
	{
		len = ft_strlen(s);
		s2 = (char *)malloc(len + 1);
		if (!s2)
			return (s2);
		i = 0;
		while (s[i])
		{
			s2[i] = (*f)(s[i]);
			i++;
		}
		s2[i] = 0;
		return (s2);
	}
	return (NULL);
}
