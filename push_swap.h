/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:47:03 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/21 23:30:14 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_node
{
	int		value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	size_t	stack_size;
	char	name;
}	t_stack;

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
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		sort_stack(t_stack *stack_a, t_stack *stack_b, int max_size);
int		checkrevsort(t_stack *currstack);
void	freearr(char **arr);
void	sort_pushback(t_stack *stack_a, t_stack *stack_b);
void	sort_checkhead(t_stack *stack_a, t_stack *stack_b);
int		stack_getmin(t_stack *currstack);
int		stack_getmax(t_stack *currstack);
t_node	*stack_maxnode(t_stack *currstack);
t_node	*stack_minnode(t_stack *currstack);

#endif