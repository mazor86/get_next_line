/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 03:42:25 by mazor             #+#    #+#             */
/*   Updated: 2020/05/21 19:00:13 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		*(ptr++) = (unsigned char)c;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joined;
	unsigned int	len1;
	unsigned int	len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(joined = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
			return (NULL);
		ft_strlcpy(joined, s1, len1 + 1);
		ft_strlcpy(joined + len1, s2, len2 + 1);
		return (joined);
	}
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_b;
	char 		*nl;
	static char *remainder = NULL;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	ft_memset(buf,'\0', BUFFER_SIZE + 1);
	while (1)
	{
		if ((nl = ft_strchr(remainder, '\n')))
		{
			free(*line);
			if (!(*line = ft_strdup(remainder)))
				return (-1);
			remainder = nl + 1;
			*nl = '\0';
			ft_putendl(*line);
			return (1);
		}
		if ((read_b = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		if (!remainder)
		{
			if (!(*line = ft_strdup(buf)))
				return (-1);
			remainder = *line;
		}
		if (!read_b)
		{
			ft_putendl(*line);
			remainder = NULL;
			return (0);
		}
		free(*line);
		if (!(*line = ft_strjoin(remainder, buf)))
			return (-1);
	}
}

int main(void)
{
	int fd = open("test", O_RDWR);
	while ()
	

}