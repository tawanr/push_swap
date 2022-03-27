# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 23:45:11 by tratanat          #+#    #+#              #
#    Updated: 2022/03/27 10:50:07 by tratanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c init_stack.c stack_op.c	\
	push_swap_utils.c stack_minmax.c stack_sort.c	\
	stack_comp.c push_queue.c sort_array.c push_swap_utils2.c

BONUS_SRCS = checker_bonus.c checker_op_bonus.c checker_utils_bonus.c	\
	checker_utils2_bonus.c checker_init_stack_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = push_swap
BONUS_NAME = checker
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
	@rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft
	@$(CC) $(BONUS_OBJS) -I$(INCLUDES) -o $(BONUS_NAME) -L$(INCLUDES) -lft
