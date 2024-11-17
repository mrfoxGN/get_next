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


#include "get_next_line_bonus.h"

static char *line(char *buffer)
{
    char *line;
    int i;

    i = 0;
    while(buffer[i] && buffer[i] != '\n')
    {
        i++;
    }
    line = ft_calloc(i + 1, sizeof(char));
    i = 0;
    while(buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if(buffer[i] != '\0' && buffer[i] == '\n')
    {
        line[i] = '\n';
    }
    return(line);
}
static char *left_from_line(char *buffer)
{
    char *left;
    int i;
    int j;
    i = 0;
    j = 0 ;
    while(buffer[i] && buffer[i] != '\n')
        i++;
    if(buffer[i] == 0)
    {
        return(NULL);
        free(buffer);
    }
    left = ft_calloc( ft_strlen(buffer) - i + 1 ,sizeof(char));
    while(buffer[i + 1])
    {
        left[j] = buffer[i + 1];
        i++;
        j++;
    }
    return(left);
}
static char *join_free(char *total_buffer,char *minibuf)
{
    char *tmp;
    tmp = ft_strjoin(total_buffer,minibuf);
    free(total_buffer);
    return(tmp);
}
static char *read_file(int fd, char *buffer)
{
    int byt_read;
    char *alocbuf;
    byt_read = 1;

    if(!buffer)
    {
        buffer = ft_calloc(1,sizeof(char));
    }
    alocbuf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if(!alocbuf)
    {
        free(buffer);
        return(NULL);
    }
    while(byt_read > 0)
    {
        byt_read = read(fd,alocbuf,BUFFER_SIZE);
        if(byt_read == -1)
        {
            free(alocbuf);
            return(NULL);
        }
        buffer = join_free(buffer,alocbuf);
        if(ft_strchr(buffer,'\n'))
            break;
    }
    free(alocbuf);
    return(buffer);

}


char *get_next_line(int fd)
{
    static char *buffer[1024];
    char *line1;
    char *phrase;

if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
    buffer[fd]= read_file(fd,buffer[fd]);
    if (!buffer[fd])
		return (NULL);
    line1 = line(buffer[fd]);
    buffer[fd] = left_from_line(buffer[fd]);
    return(line1);
}
int main()
{  
    int fd = open("ans.txt",O_RDWR | O_CREAT , 0777);
    int fd2 = open("anis.txt",O_RDWR| O_CREAT , 0777);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd2));
    

}