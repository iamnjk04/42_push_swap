/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:05:23 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:24:17 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*deallocate_line(char **line_ptr)
{
	if (*line_ptr)
		free(*line_ptr);
	return (NULL);
}

int	str_length_until_nl(const char *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '\n')
			return (len + 1);
		len++;
	}
	return (len);
}

char	*concatenate_with_newline(const char *str1, const char *str2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(str_length_until_nl(str1) + str_length_until_nl(str2) + 1);
	if (!result)
		return (result);
	i = -1;
	j = 0;
	while (str1 && str1[++i])
	{
		result[j++] = str1[i];
		if (str1[i] == '\n')
			break ;
	}
	i = -1;
	while (str2 && str2[++i])
	{
		result[j++] = str2[i];
		if (str2[i] == '\n')
			break ;
	}
	result[j] = '\0';
	return (result);
}

int	construct_line(char **line, char buf[])
{
	char	*merged;
	int		i;

	merged = concatenate_with_newline(*line, buf);
	free(*line);
	if (merged == NULL)
		return (-1);
	*line = merged;
	i = 0;
	while ((*line)[i] != '\0')
	{
		if ((*line)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	shift_remaining_chars(char *buffer)
{
	int	len;
	int	shift;
	int	i;

	len = 0;
	while (buffer[len])
		len++;
	shift = str_length_until_nl(buffer);
	i = -1;
	while (++i < len)
	{
		if (i + shift < len)
		{
			buffer[i] = buffer[i + shift];
			buffer[i + shift] = '\0';
		}
		else
			buffer[i] = '\0';
	}
}
