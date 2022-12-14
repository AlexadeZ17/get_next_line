/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:27:25 by alrodri2          #+#    #+#             */
/*   Updated: 2022/12/14 14:14:17 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_cut(const char *s1, const char *limit)
{
    char    *out;
    int     i;

    i = 0;
    out = ft_calloc(1, sizeof(char));
    while (s1 != limit)
    {
        out = ft_strjoin(out, ft_calloc(1, sizeof(char)));
        out[i] = *s1;
        ++i;
        ++s1;
        
    }
    return (out);
}

char *get_next_line(int fd)
{
    char        *line;
    char        *tmp;
    char        *lim;
    static char *buff;

    buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    //line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    read(fd, buff, BUFFER_SIZE);

    line = "";
    while (ft_strrchr(buff, '\n') == 0)
    {
        line = ft_strjoin(line, buff);
        read(fd, buff, BUFFER_SIZE);
    }

    lim = ft_strrchr(buff, '\n');
    tmp = ft_cut(buff, lim);
    line = ft_strjoin(line, tmp);
    ft_free(buff);
    buff = lim+1;
    printf("%s\n", buff);
    return (line);
}
/*
char *get_next_line(int fd)
{
    static char *buff;

    read(fd, buff, BUFFER_SIZE);
    while (ft_strrchr(buff, '\0') == 0)
    {
        get_line(buff);
        read(fd, buff, BUFFER_SIZE);
    }
    
}
*/
int main()
{
    int fd = open("test.txt", O_RDONLY); // read mode
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));

    char *str = "hola que tal";
    //printf("%s", ft_cut(str, &str[5]));
}

/*

1 -> Get the file descriptor to the file and a Buffer size
2 -> Read buffer size
3 -> Is \n in buffer:
    Yes -> Read until \n and write that into string line. Then, delete copied part from buffer and check for more \n repeating the process
    No -> Join everything into line, clear the entire buffer and read again buffer size
4 -> Return string line
5 -> Clear string line
6 -> Read buffer size

Functions needed:

1 -> strjoin, to join data from buffer to string line
2 -> putstr, to print the string
3 -> strlen, used by many other functions
4 -> free malloc, to free the buffer and string line every time


read(fd, buffer, BUFFER_SIZE)


*/