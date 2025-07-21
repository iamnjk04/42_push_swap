/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:03:48 by nakunwar          #+#    #+#             */
/*   Updated: 2025/06/27 20:25:27 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(unsigned	int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*num;
	int		len;

	len = ft_numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	i = len -1;
	if (n == 0)
		num[0] = '0';
	else
	{
		while (n != 0)
		{
			num[i--] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (num);
}

int	ft_decimal(unsigned int nb)
{
	char	*num;
	int		write_result;

	num = ft_uitoa(nb);
	if (!num)
		return (-1);
	write_result = ft_putstr_fd(num, 1);
	free(num);
	return (write_result);
}
