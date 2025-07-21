/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:03:51 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:25:23 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	ft_puthex_char(unsigned int digit, const char specifier)
{
	char	c;

	if (digit < 10)
		c = digit + '0';
	else
	{
		if (specifier == 'x')
			c = digit - 10 + 'a';
		else
			c = digit - 10 + 'A';
	}
	return (ft_putchar_fd(c, 1));
}

int	ft_puthex(unsigned int num, const char specifier)
{
	int	status;

	if (num >= 16)
	{
		status = ft_puthex(num / 16, specifier);
		if (status == -1)
			return (-1);
		status = ft_puthex(num % 16, specifier);
		if (status == -1)
			return (-1);
	}
	else
	{
		status = ft_puthex_char(num, specifier);
		if (status == -1)
			return (-1);
	}
	return (1);
}

int	ft_hex(unsigned int num, const char specifier)
{
	int	write_result;

	if (num == 0)
	{
		write_result = write(1, "0", 1);
		if (write_result == -1)
			return (-1);
		return (write_result);
	}
	write_result = ft_puthex(num, specifier);
	if (write_result == -1)
		return (-1);
	return (ft_hexlen(num));
}
