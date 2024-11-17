/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguenda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:16:40 by anguenda          #+#    #+#             */
/*   Updated: 2024/11/09 14:16:43 by anguenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr || (!s1 && !s2))
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*chaine;
	int		a;
	int		i;

	i = 0;
	a = ft_strlen(s);
	chaine = (char *)malloc((a + 1) * sizeof(char));
	if (chaine == NULL)
	{
		return (NULL);
	}
	while (s[i])
	{
		chaine[i] = s[i];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s2[start + i];
		i++;
	}
	return (p);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!count || !size)
		return (malloc(0));
	if ((count  > SIZE_MAX / size) && size != 0)
	{
		return (NULL);
	}
	ptr = malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
		{
			return (0);
		}
		s++;
	}
	return ((char *)s);
}