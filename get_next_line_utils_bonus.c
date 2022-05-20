/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:46:34 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/20 15:27:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tran;
	size_t			pos;

	tran = (unsigned char *)s;
	pos = 0;
	while (pos < n)
	{
		tran[pos] = 0;
		pos++;
	}
}

void	*ft_calloc(size_t c, size_t n)
{
	void	*rest;

	rest = 0;
	if ((c == __SIZE_MAX__ && n > 1)
		|| (n == __SIZE_MAX__ && c > 1))
		return (0);
	rest = (void *)malloc(c * n);
	if (!rest)
		return (0);
	ft_bzero(rest, (c * n));
	return (rest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
	s++;
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	pos;
	char	*esp;

	if (!s1 || !s2)
		return (0);
	esp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!esp)
		return (0);
	pos = 0;
	while (*s1)
	{
		esp[pos] = *s1;
		pos++;
		s1++;
	}
	while (*s2)
	{
		esp[pos] = *s2;
		pos++;
		s2++;
	}
	esp[pos] = '\0';
	return (esp);
}

size_t	ft_strlen(const char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		pos++;
	}
	return (pos);
}
