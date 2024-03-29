/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:20:06 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/20 20:20:32 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_getmaxdir(t_stack *stack)
{
	int		max_value;
	size_t	pos;
	t_node	*temp;

	pos = 0;
	temp = stack->head;
	max_value = stack_getmax(stack);
	while (temp->value != max_value)
	{
		pos++;
		temp = temp->next;
		if (pos > stack->stack_size / 2)
			return (0);
	}
	return (1);
}

int	stack_getmindir(t_stack *stack)
{
	int		min_value;
	size_t	pos;
	t_node	*temp;

	pos = 0;
	temp = stack->head;
	min_value = stack_getmin(stack);
	while (temp->value != min_value)
	{
		pos++;
		temp = temp->next;
		if (pos > stack->stack_size / 2)
			return (0);
	}
	return (1);
}

int	st_bdir(int value, t_stack *stack)
{
	size_t	pos;
	t_node	*temp;
	t_node	*prev;

	temp = stack->head;
	prev = stack->head->prev;
	pos = 0;
	while (!(value > prev->value && value < temp->value))
	{
		pos++;
		temp = temp->next;
		prev = temp->prev;
		if ((float)pos > (float)stack->stack_size / 2)
			return (0);
	}
	return (1);
}

int	st_brdir(int value, t_stack *stack)
{
	size_t	pos;
	t_node	*temp;
	t_node	*prev;

	temp = stack->head;
	prev = stack->head->prev;
	pos = 0;
	while (!(value < prev->value && value > temp->value))
	{
		pos++;
		temp = temp->next;
		prev = temp->prev;
		if ((float)pos > (float)stack->stack_size / 2)
			return (0);
	}
	return (1);
}

int	stack_getlims(t_stack *stack, t_lim *limits)
{
	t_node	*temp;
	int		head_dir;
	int		tail_dir;

	temp = stack->head;
	head_dir = 0;
	tail_dir = 0;
	while (!(temp->value >= limits->low_lim && temp->value <= limits->high_lim))
	{
		temp = temp->next;
		head_dir++;
	}
	temp = stack->head;
	while (!(temp->value >= limits->low_lim && temp->value <= limits->high_lim))
	{
		temp = temp->prev;
		tail_dir++;
	}
	if (head_dir > tail_dir)
		return (0);
	return (1);
}
