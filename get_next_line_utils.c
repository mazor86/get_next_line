/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 03:41:22 by mazor             #+#    #+#             */
/*   Updated: 2020/05/24 21:10:23 by mazor            ###   ########.fr       */
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

char	*ft_strdup(char *s)
{
	char	*dup;

	dup = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}

char	*strjoinfree(char *s1, char *s2, size_t len2)
{
	char	*joined;
	size_t	len1;

	if (!s1)
		s1 = ft_strdup("");
	len1 = ft_strlen(s1);
	if (!(joined = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_strlcpy(joined, s1, len1 + 1);
	ft_strlcpy(joined + len1, s2, len2 + 1);
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (joined);
}
