/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:18:04 by mvann             #+#    #+#             */
/*   Updated: 2017/09/19 16:45:04 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	t_uc	*uc_s1;
	t_uc	*uc_s2;

	uc_s1 = (t_uc*)s1;
	uc_s2 = (t_uc*)s2;
	i = 0;
	while (i < n && uc_s1[i] == uc_s2[i])
		i++;
	if (i == n)
		return (0);
	return (uc_s1[i] - uc_s2[i]);
}
