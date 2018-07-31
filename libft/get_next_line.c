/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:56:49 by mvann             #+#    #+#             */
/*   Updated: 2017/10/12 19:06:38 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_leftover(char **leftover, char **line, char **buffer)
{
	char	*tmp;
	int		i;

	if (!(tmp = ft_strchr(*leftover, '\n')))
		return (0);
	free(*buffer);
	i = 0;
	while ((*leftover)[i] != '\n')
		i++;
	if (!(*line = ft_strsub(*leftover, 0, i)))
		return (-1);
	if (!(tmp = ft_strdup(tmp + 1)))
		return (-1);
	free(*leftover);
	*leftover = tmp;
	return (1);
}

static int	append(char **leftover, char **buffer)
{
	char	*tmp;
	int		i;

	if (!(tmp = ft_strjoin(*leftover, *buffer)))
		return (0);
	free(*leftover);
	*leftover = tmp;
	i = 0;
	while (i < BUFF_SIZE)
		(*buffer)[i++] = 0;
	return (1);
}

static int	done_reading(char **leftover, char **line, char **buffer)
{
	int ret;

	if ((ret = check_leftover(leftover, line, buffer)))
		return (ret);
	free(*buffer);
	if (ft_strlen(*leftover) == 0)
		return (0);
	if (!(*line = ft_strdup(*leftover)))
		return (-1);
	free(*leftover);
	*leftover = NULL;
	return (1);
}

int			free_buffer(char **buffer)
{
	free(*buffer);
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*leftover[10000];
	char			*buffer;
	int				ret;
	char			tmp[1];

	if (!line || fd < 0 || read(fd, tmp, 0) < 0)
		return (-1);
	if (!leftover[fd])
		if (!(leftover[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((ret = check_leftover(leftover + fd, line, &buffer)))
		return (ret);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret < 0 || !append(leftover + fd, &buffer))
			return (free_buffer(&buffer));
		if ((ret = check_leftover(leftover + fd, line, &buffer)))
			return (ret);
	}
	return (done_reading(leftover + fd, line, &buffer));
}
