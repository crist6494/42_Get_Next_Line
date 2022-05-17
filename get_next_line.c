/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:22:35 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/17 20:16:45 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_readline(int fd, char *buff)
{
	int		read_pos;
	char	*read_buffer;
	
	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
	{
		free(read_buffer);
		return (0);
	}
	read_pos = 1;
	while (!ft_strchr(buff, '\n') && read_pos != 0)
	{
		read_pos = read(fd, read_buffer, BUFFER_SIZE);
		if (read_pos == -1)
		{
			free (read_buffer);
			return (0);
		}
		read_buffer[read_pos] = '\0';
		buff = ft_strjoin(buff, read_buffer);
	}
	free(read_buffer);
	return (buff);	
}

static char	*ft_get_line(char *buffer)
{
	int		pos;
	char	*line;

	pos = 0;
	if (!buffer)
		return (0);
	while (buffer[pos] && buffer[pos] != '\n')
		pos++;
	line = ft_calloc(pos + 2, sizeof(char));
	pos = 0;
	while (buffer[pos] && buffer[pos] != '\n')
	{
		line[pos] = buffer[pos];
		pos++;
	}
	if (buffer[pos] == '\n')
		line[pos++] = '\n';
	return (line);
}

static char	*ft_remove_line(char *buffer)
{
	int		pos;
	char	*aux;
	
	pos = 0;
	while (buffer[pos] && buffer[pos] != '\n')
		pos++;
	if (!buffer)
		return (0);
	aux = ft_substr(buffer, pos + 1, ft_strlen(buffer));
	free(buffer);
	return (aux);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	buffer = ft_readline(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_get_line(buffer);
	line = ft_remove_line(buffer);
	return (line);
}

/* int	main()
{
	int	fd;
	
	fd = open("pepe.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
} */