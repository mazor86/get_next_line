/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:37:08 by mazor             #+#    #+#             */
/*   Updated: 2020/05/24 23:31:21 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strdup(char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*strjoinfree(char *s1, char *s2, size_t bytes);

#endif
