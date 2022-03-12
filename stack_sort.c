/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:58:09 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/28 17:43:45 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pushback(t_stack *stack_a, t_stack *stack_b)
{
	int	max_a;
	int	min_a;
	int	max_b;

	max_a = stack_getmax(stack_a);
	min_a = stack_getmin(stack_a);
	max_b = stack_getmax(stack_b);
	while (stack_b->head->value != max_b)
		stack_rotate(stack_b);
	if (stack_getmax(stack_b) > max_a)
	{
		while (stack_a->head->prev->value != max_a)
			stack_rotate(stack_a);
		while (stack_b->head->value >= max_a)
			stack_push(stack_b, stack_a);
	}
	if (stack_a->stack_size <= 1)
		stack_push(stack_b, stack_a);
	else if (stack_b->head->value <= stack_a->head->value)
	{
		if (stack_b->head->value < min_a)
			while (stack_a->head->value > min_a)
				stack_rotate(stack_a);
		else
			while (stack_b->head->value < stack_a->head->prev->value)
				stack_reverser(stack_a);
		stack_push(stack_b, stack_a);
	}
	else
	{
		while (stack_b->head->value > stack_a->head->value)
			stack_rotate(stack_a);
		stack_push(stack_b, stack_a);
	}
}

int	stack_opt_rotate(t_stack *stack, t_node *target)
{
	int		move_count;
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
			stack_rotate(stack);
	else
		while (stack->head != target)
			stack_reverser(stack);
	return (1);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int max_size)
{
	int	max_range;
	int	min_range;

	if (checksort(stack_a))
	{

	}
}

int	list_getmedian(t_stack *stack, int max_size)
{
	char	**arr;
	int		median;

	arr = get_stackarr(stack, max_size);
	median = arr[max_size / 2];
	free(arr);
}

void	sort_checkhead(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->value > stack_a->head->next->value)
		stack_swap(stack_a);
	else if (stack_a->head->value > stack_a->head->prev->value)
		stack_reverser(stack_a);
	else
	{
		if (stack_b->stack_size <= 2)
			stack_push(stack_a, stack_b);
		else if (stack_a->head->value >= stack_b->head->value)
		{
			if (stack_a->head->value > stack_getmax(stack_b))
				while (stack_b->head->value != stack_getmax(stack_b))
					stack_rotate(stack_b);
			else
				while (stack_a->head->value > stack_b->head->prev->value)
					stack_rotate(stack_b);
			stack_push(stack_a, stack_b);
		}
		else
		{
			if (!(stack_a->head->value < stack_getmin(stack_b)))
				while (stack_a->head->value < stack_b->head->value)
					stack_rotate(stack_b);
			else
				while (stack_b->head->value != stack_getmin(stack_b))
					stack_rotate(stack_b);
			if (!(stack_a->head->value > stack_getmax(stack_b)))
				while (stack_a->head->value > stack_b->head->prev->value)
					stack_reverser(stack_b);
			else
				while (stack_b->head->value != stack_getmax(stack_b))
					stack_rotate(stack_b);
			stack_push(stack_a, stack_b);
		}
	}
}