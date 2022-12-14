/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:38:35 by alrodri2          #+#    #+#             */
/*   Updated: 2022/12/14 14:07:59 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

	out = malloc(count * size);
	if (!out)
		return (NULL);
    unsigned long	c;

	c = 0;
	while (c < (count * size))
	{
		((char *)out)[c] = (char)0;
		++c;
	}
	return (out);
}

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
		++c;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
    int     i;
    int     j;

	out = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!out)
		return (NULL);
    i = 0;
    j = 0;
 
	while (s1[i])
		out[j++] = s1[i++];
	i = 0;
	while (s2[i])
		out[j++] = s2[i++];
	out[j] = '\0';
	return (out);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*pos;

	pos = s;
	while (*s != '\0')
	{
		if (*s == (char )c)
		{
			pos = s;
			break ;
		}
		++s;
	}
	if ((char )c == '\0')
		return ((char *)s);
	else if (*pos != (char )c)
		return ((char *)0);
	return ((char *)pos);
}

void ft_free(char *str)
{
    free(str);
	str = NULL;
}