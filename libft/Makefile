# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 11:55:42 by nakunwar          #+#    #+#              #
#    Updated: 2025/07/05 15:42:47 by nakunwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_calloc.c \
       ft_isdigit.c \
       ft_memcpy.c \
       ft_putendl_fd.c \
       ft_strjoin.c \
       ft_strncmp.c \
       ft_tolower.c \
       ft_isalnum.c \
       ft_isprint.c \
       ft_memmove.c \
       ft_strlcat.c \
       ft_strnstr.c \
       ft_toupper.c \
       ft_atoi.c \
       ft_isalpha.c \
       ft_memchr.c \
       ft_memset.c \
       ft_strchr.c \
       ft_strlcpy.c \
       ft_strrchr.c \
       ft_bzero.c \
       ft_isascii.c \
       ft_memcmp.c \
       ft_strdup.c \
       ft_strlen.c \
       ft_substr.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_strtrim.c \
       ft_decimal.c \
       ft_hex.c \
       ft_number.c \
       ft_percent.c \
       ft_printf.c \
       ft_ptr.c \
       ft_putchar.c \
       ft_str.c \
       get_next_line_utils.c \
       get_next_line.c
          
OBJS = $(SRCS:.c=.o)
CC = cc
LIBC = ar rcs
RM = rm -f
INCS = libft.h
CFLAGS =  -Wall -Wextra -Werror

$(NAME): $(OBJS) $(INCS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re