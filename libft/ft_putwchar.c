/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 16:23:44 by mvann             #+#    #+#             */
/*   Updated: 2017/09/22 16:23:51 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(int c)
{
	int i;

	if ((unsigned char)c >= 240)
		i = 4;
	else if ((unsigned char)c >= 224)
		i = 3;
	else if ((unsigned char)c >= 192)
		i = 2;
	else
		i = 1;
	write(1, &c, i);
}
