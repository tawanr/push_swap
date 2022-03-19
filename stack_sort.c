/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:58:09 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/19 06:50:03 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_pushback(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	max_a;
// 	int	min_a;
// 	int	max_b;

// 	max_a = stack_getmax(stack_a);
// 	min_a = stack_getmin(stack_a);
// 	max_b = stack_getmax(stack_b);
// 	while (stack_b->head->value != max_b)
// 		stack_rotate(stack_b);
// 	if (stack_getmax(stack_b) > max_a)
// 	{
// 		while (stack_a->head->prev->value != max_a)
// 			stack_rotate(stack_a);
// 		while (stack_b->head->value >= max_a)
// 			stack_push(stack_b, stack_a);
// 	}
// 	if (stack_a->stack_size <= 1)
// 		stack_push(stack_b, stack_a);
// 	else if (stack_b->head->value <= stack_a->head->value)
// 	{
// 		if (stack_b->head->value < min_a)
// 			while (stack_a->head->value > min_a)
// 				stack_rotate(stack_a);
// 		else
// 			while (stack_b->head->value < stack_a->head->prev->value)
// 				stack_reverser(stack_a);
// 		stack_push(stack_b, stack_a);
// 	}
// 	else
// 	{
// 		while (stack_b->head->value > stack_a->head->value)
// 			stack_rotate(stack_a);
// 		stack_push(stack_b, stack_a);
// 	}
// }

void	sort_pushback(t_stack *stack_a, t_stack *stack_b, t_queue *queue)
{
	void	(*roptr[2])(t_stack *, t_queue *);
	int		dir;

	dir = 0;
	roptr[0] = &stack_reverser;
	roptr[1] = &stack_rotate;
	dir = stack_getmaxdir(stack_b);
	while (stack_b->head->value != stack_getmax(stack_b))
		roptr[dir](stack_b, queue);
	if (stack_getmax(stack_b) > stack_getmax(stack_a))
	{
		dir = stack_getmaxdir(stack_a);
		while (stack_a->head->value != stack_getmax(stack_a))
			roptr[stack_getmaxdir(stack_a)](stack_a, queue);
	}
	if (stack_getmax(stack_b) > stack_getmax(stack_a))
		while (stack_b->head->value >= stack_getmax(stack_a))
			stack_push(stack_b, stack_a, queue);
	if (stack_b->head->value <= stack_a->head->value)
	{
		if (stack_b->head->value < stack_getmin(stack_a))
		{
			dir = stack_getmindir(stack_a);
			while (stack_a->head->value > stack_getmin(stack_a))
				roptr[dir](stack_a, queue);
		}
		else
		{
			dir = st_brdir(stack_b->head->value, stack_a);
			while (!(stack_b->head->value > stack_a->head->prev->value && stack_b->head->value < stack_a->head->value))
				roptr[dir](stack_a, queue);
		}
		stack_push(stack_b, stack_a, queue);
	}
	else
	{
		dir = st_bdir(stack_b->head->value, stack_a);
		while (stack_b->head->value > stack_a->head->value)
			roptr[dir](stack_a, queue);
		stack_push(stack_b, stack_a, queue);
	}
}

int	stack_opt_rotate(t_stack *stack, t_node *target, t_queue *queue)
{
	size_t	move_count;
	t_node	*temp;

	move_count = 0;
	temp = stack->head;
	while (temp != target)
	{
		temp = temp->next;
		move_count++;
	}
	if (move_count <= stack->stack_size / 2)
		while (stack->head != target)
			stack_rotate(stack, queue);
	else
		while (stack->head != target)
			stack_reverser(stack, queue);
	return (1);
}

int	list_getmedian(t_stack *stack, int max_size)
{
	char	**arr;
	int		median;

	arr = get_stackarr(stack, max_size);
	median = ft_atoi(arr[max_size / 2]);
	free(arr);
	return (median);
}

void	sort_checkhead(t_stack *stack_a, t_stack *stack_b, t_queue *queue)
{
	void	(*roptr[2])(t_stack *, t_queue *);
	int		dir;

	roptr[0] = &stack_reverser;
	roptr[1] = &stack_rotate;
	if (stack_a->head->value > stack_a->head->next->value)
		stack_swap(stack_a, queue);
	else if (stack_a->head->value > stack_a->head->prev->value)
		stack_reverser(stack_a, queue);
	else
	{
		if (stack_b->stack_size <= 2)
			stack_push(stack_a, stack_b, queue);
		else if (stack_a->head->value >= stack_b->head->value)
		{
			if (stack_a->head->value > stack_getmax(stack_b))
			{
				dir = stack_getmaxdir(stack_b);
				while (stack_b->head->value != stack_getmax(stack_b))
					roptr[dir](stack_b, queue);
			}
			else
			{
				dir = st_brdir(stack_a->head->value, stack_b);
				while (stack_a->head->value > stack_b->head->prev->value)
					roptr[dir](stack_b, queue);
			}
			stack_push(stack_a, stack_b, queue);
		}
		else
		{
			if (!(stack_a->head->value < stack_getmin(stack_b)))
			{
				dir = st_bdir(stack_a->head->value, stack_b);
				while (stack_a->head->value < stack_b->head->value)
					roptr[dir](stack_b, queue);
			}
			else
			{
				dir = stack_getmindir(stack_b);
				while (stack_b->head->value != stack_getmin(stack_b))
					roptr[dir](stack_b, queue);
			}
			if (!(stack_a->head->value > stack_getmax(stack_b)))
			{
				dir = st_brdir(stack_a->head->value, stack_b);
				while (stack_a->head->value > stack_b->head->prev->value)
					roptr[dir](stack_b, queue);
			}
			else
			{
				dir = stack_getmaxdir(stack_b);
				while (stack_b->head->value != stack_getmax(stack_b))
					roptr[dir](stack_b, queue);
			}
			stack_push(stack_a, stack_b, queue);
		}
	}
}

// void	sort_checkhead(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (stack_a->head->value > stack_a->head->next->value)
// 		stack_swap(stack_a);
// 	else if (stack_a->head->value > stack_a->head->prev->value)
// 		stack_reverser(stack_a);
// 	else
// 	{
// 		if (stack_b->stack_size <= 2)
// 			stack_push(stack_a, stack_b);
// 		else if (stack_a->head->value >= stack_b->head->value)
// 		{
// 			if (stack_a->head->value > stack_getmax(stack_b))
// 				while (stack_b->head->value != stack_getmax(stack_b))
// 					stack_rotate(stack_b);
// 			else
// 				while (stack_a->head->value > stack_b->head->prev->value)
// 					stack_rotate(stack_b);
// 			stack_push(stack_a, stack_b);
// 		}
// 		else
// 		{
// 			if (!(stack_a->head->value < stack_getmin(stack_b)))
// 				while (stack_a->head->value < stack_b->head->value)
// 					stack_rotate(stack_b);
// 			else
// 				while (stack_b->head->value != stack_getmin(stack_b))
// 					stack_rotate(stack_b);
// 			if (!(stack_a->head->value > stack_getmax(stack_b)))
// 				while (stack_a->head->value > stack_b->head->prev->value)
// 					stack_reverser(stack_b);
// 			else
// 				while (stack_b->head->value != stack_getmax(stack_b))
// 					stack_rotate(stack_b);
// 			stack_push(stack_a, stack_b);
// 		}
// 	}
// }