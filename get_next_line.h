/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:42:46 by alrodri2          #+#    #+#             */
/*   Updated: 2022/12/14 12:19:33 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

void    *ft_calloc(size_t count, size_t size);
int     ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strrchr(const char *s, int c);
void    ft_free(char *str);
char    *get_next_line(int fd);
void    ft_free(char *str);
#endif
