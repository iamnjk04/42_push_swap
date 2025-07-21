/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:52:29 by nakunwar          #+#    #+#             */
/*   Updated: 2025/03/20 15:08:52 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strchr(char *ptr, int search_str)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == (char)search_str)
			return ((char *)(ptr + i));
		i++;
	}
	if (ptr[i] == (char)search_str)
		return ((char *)(ptr + i));
	return (NULL);
}
// #include<stdio.h>