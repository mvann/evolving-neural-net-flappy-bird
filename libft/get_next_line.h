/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 10:14:44 by mvann             #+#    #+#             */
/*   Updated: 2017/11/09 18:43:25 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 20

typedef struct		s_fd_str
{
	int				fd;
	char			*str;
}					t_fd_str;

typedef struct		s_buff
{
	char			str[BUFF_SIZE];
	int				i;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
