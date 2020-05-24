/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:18:31 by mazor             #+#    #+#             */
/*   Updated: 2020/05/24 21:16:01 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		free_mem(char **rem_ptr, char **buf_ptr)
{
	if (*rem_ptr)
	{
		free(*rem_ptr);
		*rem_ptr = NULL;
	}
	if (*buf_ptr)
	{
		free(*buf_ptr);
		*buf_ptr = NULL;
	}
	return (-1);
}

static int		print_line(char **src, char **dest, char **buf_ptr)
{
	if (!(*src))
		return (free_mem(src, buf_ptr) + 1);
	write(1, *src, ft_strlen(*src));
	if (src == dest)
		return ((int)write(1, "\n", 1));
	*dest = ft_strdup(*src);
	return (free_mem(src, buf_ptr) + 1);
}

static int		nl_search(char **rem_ptr, char **line)
{
	size_t	i;
	char	*new_rem;

	i = 0;
	while ((*rem_ptr)[i])
	{
		if ((*rem_ptr)[i] == '\n')
		{
			new_rem = ft_strdup(*rem_ptr + i + 1);
			(*rem_ptr)[i] = '\0';
			*line = ft_strdup(*rem_ptr);
			free(*rem_ptr);
			*rem_ptr = NULL;
			if (!new_rem || !(*line))
				return (free_mem(&new_rem, line));
			*rem_ptr = new_rem;
			return (print_line(line, line, NULL));
		}
		i++;
	}
	return (0);
}

static ssize_t	read_buf(int fd, char **buf_ptr, size_t size, char **rem_ptr)
{
	ssize_t	read_b;

	read_b = read(fd, *buf_ptr, size);
	if (read_b <= 0)
		return ((int)read_b);
	if (!(*rem_ptr = strjoinfree(*rem_ptr, *buf_ptr, read_b)))
		return (-1);
	return (read_b);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainder = NULL;
	char		*buf;
	ssize_t		read_b;
	int			flag;

	buf = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (free_mem(&remainder, &buf));
	while (1)
	{
		if (remainder)
		{
			if ((flag = nl_search(&remainder, line)))
				return (flag);
		}
		if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (free_mem(&remainder, &buf));
		buf[BUFFER_SIZE] = '\0';
		if (!(read_b = read_buf(fd, &buf, BUFFER_SIZE, &remainder)))
			return (print_line(&remainder, line, &buf));
		if (read_b < 0)
			return (free_mem(&remainder, &buf));
	}
}
