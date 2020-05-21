/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 03:41:22 by mazor             #+#    #+#             */
/*   Updated: 2020/05/21 18:47:16 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

void	ft_putendl(const char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (!c)
		return ((char*)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;

	if (src && dst)
	{
		dst_len = (size - 1);
		src_len = ft_strlen(src);
		if (size)
		{
			while (*src && dst_len--)
			{
				*dst++ = *src++;
			}
			*dst = '\0';
		}
		return ((src_len));
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}
