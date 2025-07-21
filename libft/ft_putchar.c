/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:32:28 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:24:25 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	int	result;

	result = write(fd, &c, 1);
	if (result == -1)
		return (-1);
	else
		return (1);
}

int	ft_putchar(int c)
{
	return (ft_putchar_fd(c, 1));
}
