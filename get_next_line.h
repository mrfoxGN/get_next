/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguenda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:45 by anguenda          #+#    #+#             */
/*   Updated: 2024/11/09 14:18:20 by anguenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
# include <stdint.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char	*ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

void	*ft_calloc(size_t count, size_t size);
#endif