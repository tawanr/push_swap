/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:47:03 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/23 08:54:34 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	size_t			stack_size;
	char			name;
}	t_stack;

typedef struct s_queue
{
	int	rotate_a;
	int	rotate_b;
}	t_queue;

typedef struct s_lim
{
	int	low_lim;
	int	high_lim;
	int	next_lim;
}	t_lim;

t_stack	*init_stack(int *num_list, size_t size, char name);
int		stack_appendnew(t_stack *currstack, int num);
void	stack_free(t_stack *currstack);
void	stack_swap(t_stack *currstack);
void	stack_rotate(t_stack *currstack);
void	stack_reverser(t_stack *currstack);
void	stack_push(t_stack *stack_from, t_stack *stack_to);
int		get_numarr(int *num_list, char **charlist, int size);
int		checknum(char *str);
int		checksort(t_stack *currstack);
char	**get_stackarr(t_stack *stack, size_t max_stack);
t_queue	*initqueue(void);
void	ft_cleanup(t_stack *stack_a, t_stack *stack_b);
void	printrot(int *rotate_a, int *rotate_b);
void	printerror(int *num_list);
void	rotate_target(t_stack *sta, t_stack *stb, t_queue *queue);
void	stack_bothswap(t_stack *sta, t_stack *stb);
void	check_stack(t_stack *stack);
int		doop(t_stack *stack_a, t_stack *stack_b);
int		doop_rotate(char *op, t_stack *stack_a, t_stack *stack_b);

#endif