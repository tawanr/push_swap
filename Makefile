# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 23:45:11 by tratanat          #+#    #+#              #
#    Updated: 2022/02/21 17:33:03 by tratanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c init_stack.c stack_op.c

BONUS_SRCS = $(SRCS)

NAME = push_swap
CC = gcc -Wextra -Wall -Werror
INCLUDES = ./libft/

all: $(NAME)

$(NAME): $(SRCS) push_swap.h
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft
	@$(CC) -o $(NAME) -I$(INCLUDES) -g $(SRCS) -L$(INCLUDES) -lft

clean:
	@$(MAKE) clean -C ./libft
	rm -rf *.o

fclean: clean
	@$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_SRCS)
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft
	@$(CC) -o $(NAME) -I$(INCLUDES) $(BONUS_SRCS) -L$(INCLUDES) -lft
