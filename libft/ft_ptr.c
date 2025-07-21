/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:04:01 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:24:32 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(uintptr_t num)
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

int	ft_putptr(uintptr_t num)
{
	int	result;

	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			result = ft_putchar_fd((num + '0'), 1);
			if (result == -1)
				return (-1);
		}
		else
		{
			result = ft_putchar_fd((num - 10 + 'a'), 1);
			if (result == -1)
				return (-1);
		}
	}
	return (1);
}

int	ft_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (length == -1)
		return (-1);
	if (ptr == 0)
	{
		length += write(1, "0", 1);
		if (length == -1)
			return (-1);
	}
	else
	{
		ft_putptr(ptr);
		length += ft_ptrlen(ptr);
	}
	return (length);
}
