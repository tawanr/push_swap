/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:47:03 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/29 22:22:35 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
	int				sorted;
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
	int	*arr;
}	t_lim;

t_stack	*init_stack(int *num_list, size_t size, char name);
int		stack_appendnew(t_stack *currstack, int num);
void	stack_free(t_stack *currstack);
void	stack_swap(t_stack *currstack, t_queue *queue);
void	stack_rotate(t_stack *currstack, t_queue *queue);
void	stack_reverser(t_stack *currstack, t_queue *queue);
void	stack_push(t_stack *stack_from, t_stack *stack_to, t_queue *queue);
int		get_numarr(int *num_list, char **charlist, int size);
int		checknum(char *str);
int		checksort(t_stack *currstack);
char	**get_stackarr(t_stack *stack, size_t max_stack);
int		sort_stack(t_stack *stack_a, t_stack *stack_b, int max_size);
void	sort_pushback(t_stack *stack_a, t_stack *stack_b, t_queue *queue);
void	sort_checkhead(t_stack *sta, t_stack *stb, t_queue *queue, t_lim *lims);
int		stack_getmin(t_stack *currstack);
int		stack_getmax(t_stack *currstack);
t_node	*stack_maxnode(t_stack *currstack);
t_node	*stack_minnode(t_stack *currstack);
int		stack_getmaxdir(t_stack *stack);
int		stack_getmindir(t_stack *stack);
int		st_bdir(int value, t_stack *stack);
int		st_brdir(int value, t_stack *stack);
t_queue	*initqueue(void);
void	addqueue(int op, char name, t_queue *queue);
void	flushqueue(int op, char name, t_queue *queue);
int		getsortedarr(t_stack *stack, int **array);
void	recursivesort(int *array, int low, int high);
int		quicksort(int *array, int low, int high);
void	ft_swap(int *a, int *b);
int		inlims(t_lim *limits, t_stack *stack_a);
int		stack_getlims(t_stack *stack, t_lim *limits);
void	dosort(t_stack *stack_a, t_stack *stack_b, t_queue *queue, size_t size);
void	getlims(t_lim *limits, int *array, int div, int arr_size);
void	ft_cleanup(t_stack *stack_a, t_stack *stack_b, t_queue *queue);
void	stack_arrange(t_stack *stack_a, t_queue *queue);
void	printrot(int *rotate_a, int *rotate_b);
void	printerror(int *num_list);
void	push_main(t_stack *sta, t_stack *stb, t_queue *queue);
void	rotate_target(t_stack *sta, t_stack *stb, t_queue *queue);
void	stack_bothswap(t_stack *sta, t_stack *stb, t_queue *queue);

#endif