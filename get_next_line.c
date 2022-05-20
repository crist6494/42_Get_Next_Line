/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:22:35 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/20 10:37:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freespace(char *res, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(res, buffer);
	free(res);
	return (aux);
}

char	*ft_read_line(int fd, char *res)
{
	char	*buffer;
	int		read_buffer;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_buffer = 1;
	while (read_buffer > 0)
	{
		read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[read_buffer] = '\0';
		res = ft_freespace(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		pos;

	pos = 0;
	if (!buffer[pos])
		return (0);
	while (buffer[pos] && buffer[pos] != '\n')
	pos++;
	line = ft_calloc(pos + 2, sizeof(char));
	pos = 0;
	while ((buffer[pos] && buffer[pos] != '\n'))
	{
		line[pos] = buffer[pos];
		pos++;
	}
	if (buffer[pos] && buffer[pos] == '\n')
		line[pos] = '\n';
	return (line);
}

char	*ft_remove_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_get_line(buffer);
	buffer = ft_remove_line(buffer);
	return (line);
}
