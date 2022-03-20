# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 23:45:11 by tratanat          #+#    #+#              #
#    Updated: 2022/03/20 17:51:10 by tratanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c init_stack.c stack_op.c	\
	push_swap_utils.c stack_minmax.c stack_sort.c	\
	stack_comp.c push_queue.c sort_array.c push_swap_utils2.c

BONUS_SRCS = $(SRCS)

OBJS = $(SRCS:.c=.o)

NAME = push_swap
CC = gcc
CFLAGS = -Wextra -Wall -Werror
INCLUDES = ./libft/

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft
	@$(CC) $(OBJS) -g -I$(INCLUDES) -o $(NAME) -L$(INCLUDES) -lft
clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

bonus: $(BONUS_SRCS)
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft
	@$(CC) -o $(NAME) -I$(INCLUDES) $(BONUS_SRCS) -L$(INCLUDES) -lft
