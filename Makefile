# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 16:20:46 by nakunwar          #+#    #+#              #
#    Updated: 2025/07/05 15:25:02 by nakunwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g 
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = utils.c move.c sort.c main.c
SRC	= $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME) 
	@echo "Done!"
	@echo "To test the program, run 'make test' or 'make test size=10'"
	@echo "for example for testing 10 random numbers"
	@echo "./push_swap 1 2 3 4 5 6 7 8 9 10"

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $? -I./$(LIBFT_DIR)
	@mv *.o src

clean:	
	@$(RM) src/*.o
	@make -s -C $(LIBFT_DIR) clean

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all clean

.PHONY: all clean fclean test re

OS := $(shell uname)
size ?= 10

ifeq ($(OS),Linux)
	CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
	CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

test:
	@$(eval ARG := $(shell python3 -c 'import random; print(" ".join(map(str, random.sample(range(1, $(size)+1), $(size)))))'))
	@echo "Test ARG: $(ARG)"
	@echo "Checker result:"
	@./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo "Instructions count:"
	@./push_swap $(ARG) | wc -l
