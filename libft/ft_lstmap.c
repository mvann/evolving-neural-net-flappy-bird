/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:25:42 by mvann             #+#    #+#             */
/*   Updated: 2017/09/21 17:55:03 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = (*f)(lst);
	tmp = ft_lstnew(tmp->content, tmp->content_size);
	tmp->next = ft_lstmap(lst->next, f);
	return (tmp);
}
