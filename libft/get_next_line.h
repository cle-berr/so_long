/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:51:49 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/05 11:03:28 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ftstrlcpy(char *dst, const char *src, size_t size);
char	*get_next_line(int fd);
char	*ftstrchr(const char *s, char c);
char	*ftstrjoin(char *s1, char *s2);
char	*ftstrdup(const char *s);
int		ftstrlen(char *s);

#endif
