/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:44:32 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/29 22:50:52 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_pushsort(t_stack *sta, t_stack *stb, t_queue *queue, int *array)
{
	void	(*roptr[2])(t_stack *, t_queue *);
	int		dir;
	t_lim	limits;
	int		div;
	int		arr_size;

	dir = 0;
	div = 1;
	arr_size = sta->stack_size + stb->stack_size;
	roptr[0] = &stack_reverser;
	roptr[1] = &stack_rotate;
	if (arr_size > 50 && arr_size <= 20)
		div = arr_size / 13;
	else if (arr_size > 200)
		div = arr_size / 25;
	limits.arr = array;
	while (stb->stack_size > 0)
	{
		getreverselims(&limits, array, div, arr_size);
		while (!nodeinlims(&limits, stb->head))
			stack_rotate(sta, queue);
		stack_pushlims(&limits, sta, stb, queue);
	}
}

void	stack_pushlims(t_lim *lims, t_stack *sta, t_stack *stb, t_queue *que)
{
	int		dir;
	void	(*roptr[2])(t_stack *, t_queue *);
	t_lim	lowlim;
	t_lim	uplim;

	roptr[0] = &stack_reverser;
	roptr[1] = &stack_rotate;
	dir = stack_getmaxlims(stb, lims);
	while (!nodeinlims(lims, stb->head, 2) && inlimsback(lims, stb))
		roptr[dir](stb, que);
	while (inlims(lims, stb))
	{
		if (nodeinlims(lims, stb->head, 0))
			stack_push(stb, sta, que);
		dir = stack_getlims(stb, lims);
		while (!nodeinlims(lims, stb->head, 0))
			roptr[dir](stb, que);
	}
	while (!(sta->head->prev->value <= lims->high_lim \
	&& sta->head->value >= lims ->next_lim))
		stack_rotate(sta, que);
	while (!inlims(lims, stb) && inlimsback(lims, stb))
	{
		if (nodeinlims(lims, stb->head, 1))
			stack_push(stb, sta, que);
		dir = stack_getmaxlims(stb, lims);
		while (!nodeinlims(lims, stb->head, 1))
			roptr[dir](stb, que);
	}
	if (!inlimsback(lims, stb))
	{
		splitlims(lims, &lowlim, &uplim);
		stack_repush(sta, stb, &uplim, que);
		stack_repush(sta, stb, &lowlim, que);
	}
}

void	stack_repush(t_stack *sta, t_stack *stb, t_lim *lims, t_queue *que)
{
	t_lim	uplim;
	t_lim	lowlim;

	if (lims->low_lim == lims->high_lim || lims->high_lim == lims->next_lim)
		return ;
	check_sortlims(sta, lims);
	while (!nodeinlims(lims, sta->head, 1))
		stack_rotate(sta, que);
	while (nodeinlims(lims, sta->head, 2))
		if (sta->head->sorted == 0)
			stack_push(sta, stb, que);
	while (sta->head->value != lims->high_lim)
		stack_reverser(sta, que);
	while (nodeinlims(lims, stb->head, 0))
		stack_push(stb, sta, que);
	stack_rotate(sta, que);
	while (nodeinlims(lims, stb->head, 1))
		stack_push(stb, sta, que);
	if (!inlimsback(lims, stb))
	{
		splitlims(lims, &lowlim, &uplim);
		stack_repush(sta, stb, &uplim, que);
		stack_repush(sta, stb, &lowlim, que);
	}
}

void	stack_nameswap(t_stack *stack1, t_stack *stack2, t_queue *queue)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (stack1->name == 'a')
	{
		stack_a = stack1;
		stack_b = stack2;
	}
	else
	{
		stack_a = stack2;
		stack_b = stack1;
	}
	stack_swapsort(stack_a, stack_b, queue);
}

void	stack_swapsort(t_stack *stack_a, t_stack *stack_b, t_queue *queue)
{
	if (stack_a->head->value > stack_a->head->next->value)
	{
		if (stack_b->head->value < stack_b->head->next->value)
			stack_bothswap(stack_a, stack_b, queue);
		else
			stack_swap(stack_a, queue);
	}
	else if (stack_b->head->value < stack_b->head->next->value)
		stack_swap(stack_b, queue);
}

void	getreverselims(t_lim *limits, int *array, int div, int arr_size)
{
	static int	count = 0;
	int			segm;

	segm = arr_size / div;
	count++;
	if (count == div)
	{
		limits->low_lim = array[0];
		limits->high_lim = array[arr_size - ((count - 1) * segm / 2) - 1];
		limits->next_lim = array[arr_size - ((count - 1) * segm) - 1];
	}
	else
	{
		limits->next_lim = array[arr_size - ((count - 1) * segm) - 1];
		limits->high_lim = array[arr_size - ((count - 1) * segm / 2) - 1];
		limits->low_lim = array[arr_size - (count * segm) - 1];
	}
}

int	checklimsort(t_lim *limits, int *array, t_stack *stack)
{
	int		i;
	t_node	*temp;

	temp = stack->head;
	i = 0;
	while (array[i] != limits->low_lim)
		i++;
	while (temp->value != array[i])
	{
		if (temp->value < limits->low_lim || temp->value > limits->high_lim)
			return (0);
		temp = temp->prev;
	}
	while (array[i] != limits->high_lim)
	{
		if (array[i++] == temp->value)
			temp = temp->next;
		else
			return (0);
	}
}
