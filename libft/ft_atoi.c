/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:25:14 by nakunwar          #+#    #+#             */
/*   Updated: 2025/07/04 15:31:31 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str, int *error)
{
	long	n;
	int		s;

	n = 0;
	s = 1;
	*error = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		s = 1 - 2 * (*str++ == '-');
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str++ - '0');
		if ((s == 1 && n > INT_MAX) || (s == -1 && n > (long)INT_MAX + 1))
			*error = 1;
	}
	if (*str != '\0')
		*error = 1;
	return ((int)(n * s));
}

// #include<stdio.h>
// int main()
// {
//     char str[] = "\n\t  -+----897dd";
//     int val = ft_atoi(str);
//     printf ("%d\n", val);
//     return 0;
// }