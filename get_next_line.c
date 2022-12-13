/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:27:25 by alrodri2          #+#    #+#             */
/*   Updated: 2022/12/12 16:25:31 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char ft_cut(const char *s1, const char *limit)
{
    char    *out;
    int     i;

    i = 0;
    out = ft_calloc(1, sizeof(char));
    while (s1 != limit)
    {
        out = ft_calloc(1, sizeof(char));
        out[i] = s1[i];
        ++i;
        ++s1;
        
    }
    return (out);
}

char *get_next_line(int fd)
{
    char *line;
    static char *save;
    char *tmp;

    save = ft_calloc(BUFFER_SIZE, sizeof(char));
    read(fd, save, BUFFER_SIZE);
    if (ft_strrchr(save, '\n') == 0)
    {
        line = ft_strjoin(line, save);
        ft_free(save);
    }
    else
    {
        tmp = ft_cut(save, ft_strrchr(save, '\n'));
        line = ft_strjoin(line, tmp);
        tmp = save;
        ft_free(save);
        save = tmp;
        return (line);
    }
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