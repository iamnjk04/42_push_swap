/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:06:00 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:39:26 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	read_buffer[BUFFER_SIZE + 1];
	char		*result_line;
	int			flag;
	int			bytes_read;

	result_line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	while (1)
	{
		if (read_buffer[0] == '\0')
		{
			bytes_read = read(fd, read_buffer, BUFFER_SIZE);
			if (bytes_read == -1)
				return (deallocate_line(&result_line));
			if (bytes_read == 0)
				return (result_line);
		}
		flag = construct_line(&result_line, read_buffer);
		shift_remaining_chars(read_buffer);
		if (flag == 1)
			return (result_line);
		if (flag == -1)
			return (NULL);
	}
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test1.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
