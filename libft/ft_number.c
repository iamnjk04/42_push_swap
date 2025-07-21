/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:03:53 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:33:06 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_recursive(int n, int fd)
{
	int	result;
	int	total;

	total = 0;
	if (n >= 10)
	{
		result = ft_putnbr_recursive((int)n / 10, fd);
		if (result == -1)
			return (-1);
		total += result;
	}
	result = ft_putchar_fd((n % 10) + '0', fd);
	if (result == -1)
		return (-1);
	return (total + result);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	result;
	int	sign;

	sign = 0;
	if (n == -2147483648)
	{
		sign = 2;
		if (ft_putchar_fd ('-', fd) == -1 || ft_putchar_fd ('2', fd) == -1)
			return (-1);
		n = 147483648;
	}
	else if (n < 0)
	{
		sign = 1;
		if (ft_putchar_fd ('-', fd) == -1)
			return (-1);
		n = -n;
	}
	result = ft_putnbr_recursive(n, fd);
	if (result == -1)
		return (-1);
	return (sign + result);
}

int	ft_number(int n)
{
	return (ft_putnbr_fd(n, 1));
}
