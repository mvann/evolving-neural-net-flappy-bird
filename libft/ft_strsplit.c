/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:04:12 by mvann             #+#    #+#             */
/*   Updated: 2017/09/26 18:11:40 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**get_pieces(char const *s, char c, char **pieces, int num_pieces)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = 0;
		while (s[i + k] && s[i + k] != c)
			k++;
		pieces[j] = (char *)malloc(k + 1);
		if (!(pieces[j]))
			return (NULL);
		k = 0;
		while (s[i] && s[i] != c)
			pieces[j][k++] = s[i++];
		pieces[j][k] = 0;
		j++;
	}
	pieces[num_pieces] = NULL;
	return (pieces);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		num_pieces;
	char	**pieces;

	if (!s)
		return (NULL);
	i = 0;
	num_pieces = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			num_pieces++;
		while (s[i] && s[i] != c)
			i++;
	}
	pieces = (char **)malloc(sizeof(char *) * (num_pieces + 1));
	if (!pieces)
		return (NULL);
	return (get_pieces(s, c, pieces, num_pieces));
}
