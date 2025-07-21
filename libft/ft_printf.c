/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:01:06 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:24:36 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_specifiers(va_list args, const char specifier)
{
	int	length;

	if (specifier == 'c')
		length = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		length = ft_str(va_arg(args, char *));
	else if (specifier == 'p')
		length = ft_ptr(va_arg(args, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		length = ft_number(va_arg(args, int));
	else if (specifier == 'u')
		length = ft_decimal(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		length = ft_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		length = ft_percent();
	else
	{
		length = ft_putchar('%');
		if (length != -1)
			length += ft_putchar(specifier);
	}
	return (length);
}

static int	ft_process_segment(const char *str, int *i, va_list args, int *len)
{
	int	ret;

	if (str[*i] == '%')
	{
		ret = ft_specifiers(args, str[*i + 1]);
		if (ret == -1)
			return (-1);
		*len += ret;
		*i += 2;
	}
	else
	{
		ret = ft_putchar(str[*i]);
		if (ret == -1)
			return (-1);
		*len += ret;
		(*i)++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (ft_process_segment(str, &i, args, &length) == -1)
			return (va_end(args), -1);
	}
	va_end(args);
	return (length);
}
