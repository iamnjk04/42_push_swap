/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:32:12 by nakunwar          #+#    #+#             */
/*   Updated: 2025/07/05 15:42:39 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *ptr1, const char *ptr2, size_t n);
int		ft_atoi(const char *str, int *error);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *ptr, int search_str, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void	*ft_memcpy(void *ptr1, const void *ptr2, size_t n);
void	*ft_memmove(void *ptr1, const void *ptr2, size_t n);
void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_strchr(char *ptr, int search_str);
char	*ft_strdup(const char *str);
size_t	ft_strlcat(char *ptr1, const char *ptr2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_strrchr(const char *ptr, int search_str);
int		ft_tolower(int c);
int		ft_toupper(int c);
// void	ft_putchar_fd(char c, int fd);
// void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
// void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_count_words(char const *s, char c);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);

//ft_printf

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
// static int	ft_numlen(unsigned	int num);
char	*ft_uitoa(unsigned int n);
int		ft_decimal(unsigned int nb);
int		ft_putnbr_fd(int n, int fd);
int		ft_number(int n);
size_t	ft_strlen(const char *str);
int		ft_specifiers(va_list args, const char specifier);
int		ft_putstr_fd(char *s, int fd);
int		ft_str(char *str);
int		ft_percent(void);
int		ft_puthex(unsigned int num, const char format);
int		ft_hex(unsigned int num, const char format);
int		ft_ptr(unsigned long long ptr);
int		ft_hexlen(unsigned	int num);
int		ft_ptrlen(uintptr_t num);
int		ft_putchar_fd(char c, int fd);

// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		str_length_until_nl(const char *str);
char	*concatenate_with_newline(const char *s1, const char *s2);
void	shift_remaining_chars(char *buffer);
int		construct_line(char **line, char buf[]);
char	*deallocate_line(char **line_ptr);

#endif