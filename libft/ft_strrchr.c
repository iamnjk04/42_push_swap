/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:25:19 by nakunwar          #+#    #+#             */
/*   Updated: 2025/03/20 15:09:25 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strrchr(const char *ptr, int search_str)
{
	int	i;

	i = ft_strlen(ptr) - 1;
	while (i >= 0)
	{
		if (ptr[i] == (char)search_str)
			return ((char *)(ptr + i));
		i--;
	}
	if ((char)search_str == '\0')
		return ((char *)(ptr + ft_strlen(ptr)));
	return (NULL);
}
// int main() {
//     const char *str = "Hello, World!";
//     char *result = ft_strrchr(str, '\0');

//     if (result)
//         printf("Character found: %s\n", result);
//     else
//         printf("Character not found.\n");

//     return 0;
// }