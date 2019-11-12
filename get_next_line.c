/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:06:08 by mroux             #+#    #+#             */
/*   Updated: 2019/11/12 12:57:16 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		get_next_line(int fd, char **line)
{
	static char		*buffer = 0;
	static size_t	pos = 0;
	static int		bytes_read = 0;
	size_t			ln;

	ln = 0;
	if (line == 0 || !(*line = (char *)malloc(1 * sizeof(char))))
		return (-1);
	(*line)[0] = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 ||
		init(&buffer, fd, &bytes_read) == -1)
		return (-1);
	while (find_line(buffer, bytes_read, pos, &ln) == 0)
	{
		*line = ft_strnjoin(*line, &buffer[pos], ln);
		pos = 0;
		if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) < 0)
			return (-1);
		if (bytes_read == 0)
			return (reinit(&buffer, &pos, &bytes_read));
		//	return (ln == 0 ? reinit(&buffer, &pos, &bytes_read) : 1);
	}
	*line = ft_strnjoin(*line, &buffer[pos], ln);
	pos += ln + 1;
	return (1);
}
