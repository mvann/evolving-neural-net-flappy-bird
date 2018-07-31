/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:42:16 by mvann             #+#    #+#             */
/*   Updated: 2017/09/21 16:59:12 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!content)
		content_size = 0;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	if (content)
		ft_memcpy(new->content, content, content_size);
	else
		new->content = NULL;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
