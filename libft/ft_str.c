/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:04:08 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:24:21 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	ssize_t	bytes;

	if (!s && fd < 0)
		return (-1);
	bytes = write(fd, s, ft_strlen(s));
	if (bytes == -1)
		return (-1);
	return ((int)bytes);
}

int	ft_str(char *str)
{
	int	result;

	if (!str)
	{
		result = ft_putstr_fd("(null)", 1);
		return (result);
	}
	result = ft_putstr_fd(str, 1);
	return (result);
}
