/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguenda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:29:22 by anguenda          #+#    #+#             */
/*   Updated: 2024/11/11 17:18:34 by anguenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
	{
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*left_from_line(char *buffer)
{
	char	*left;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (NULL);
	}
	left = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	while (buffer[i + 1])
	{
		left[j] = buffer[i + 1];
		i++;
		j++;
	}
	free(buffer);
	return (left);
}

static char	*join_free(char *total_buffer, char *minibuf)
{
	char	*tmp;

	tmp = ft_strjoin(total_buffer, minibuf);
	free(total_buffer);
	return (tmp);
}

static char	*read_file(int fd, char *buffer)
{
	int		byt_read;
	char	*alocbuf;

	byt_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	alocbuf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (byt_read > 0)
	{
		byt_read = read(fd, alocbuf, BUFFER_SIZE);
		if (byt_read == -1)
		{
			free(alocbuf);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		alocbuf[byt_read] = '\0';
		buffer = join_free(buffer, alocbuf);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(alocbuf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line1;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
        return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
	{
		buffer = NULL;
		return (NULL);
	}
	line1 = line(buffer);
	buffer = left_from_line(buffer);
	return (line1);
}
