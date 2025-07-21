/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:09:27 by nakunwar          #+#    #+#             */
/*   Updated: 2025/03/20 16:09:31 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ptr;
	size_t	str1_len;
	size_t	str2_len;

	str1_len = 0;
	str2_len = 0;
	if (str1)
		str1_len = ft_strlen(str1);
	if (str2)
		str2_len = ft_strlen(str2);
	ptr = malloc(str1_len + str2_len + 1);
	if (!ptr)
		return (NULL);
	if (str1)
		ft_memcpy(ptr, str1, str1_len);
	if (str2)
		ft_memcpy(ptr + str1_len, str2, str2_len);
	ptr[str1_len + str2_len] = '\0';
	return (ptr);
}
// #include<stdio.h>
// int main()
// {
// 	char * str1 = ft_strjoin("ftufh", "hdrhd");
// 	// char str2[] = "World!";
// 	printf("%s\n", str1);
// }