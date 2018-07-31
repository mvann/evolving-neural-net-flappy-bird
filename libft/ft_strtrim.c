/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 20:33:49 by mvann             #+#    #+#             */
/*   Updated: 2017/09/26 18:13:18 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_ws(int *i, char const *s, int len)
{
	*i = 0;
	while (s[len - (*i) - 1] == ' ' || s[len - (*i) - 1] == '\n'
		|| s[len - (*i) - 1] == '\t')
		(*i)++;
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		s2_len;
	int		front;
	char	*s2;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	front = 0;
	while (s[front] == ' ' || s[front] == '\n' || s[front] == '\t')
		front++;
	skip_ws(&i, s, len);
	s2_len = len - (i + front);
	if (s2_len < 0)
		s2_len = 0;
	s2 = (char *)malloc(s2_len + 1);
	if (!s2)
		return (s2);
	i = -1;
	while (++i < s2_len)
		s2[i] = s[front + i];
	s2[i] = 0;
	return (s2);
}
