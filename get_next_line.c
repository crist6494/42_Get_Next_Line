/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:22:35 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/16 20:00:16 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_readline(int	fd, char	*buffer)
{
	int		read_pos;
	char	*read_buffer;
	
	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
	{
		free(read_buffer);
		return (0);
	}
	read_pos = 0;
	while (!ft_strchr(buffer, '\n') && read_pos != 0)
	{
		read_pos = read(fd, read_buffer, BUFFER_SIZE);
		if (read_pos < 0)
		{
			free (read_buffer);
			return (0);
		}
		read_buffer[read_pos] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
	}
	free(read_buffer);
	return (buffer);	
}