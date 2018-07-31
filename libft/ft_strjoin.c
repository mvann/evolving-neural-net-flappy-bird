/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 20:22:21 by mvann             #+#    #+#             */
/*   Updated: 2017/09/21 16:24:24 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc(s1_len + s2_len + 1);
	if (!s3)
		return (s3);
	i = -1;
	while (++i < s1_len)
		s3[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		s3[s1_len + i] = s2[i];
	s3[s1_len + s2_len] = 0;
	return (s3);
}
