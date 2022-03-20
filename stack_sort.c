/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:58:09 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/20 21:22:38 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			roptr[dir](stack_a, queue);
		dir = stack_getmaxdir(stack_b);
		while (!(stack_b->head->value > stack_getmax(stack_a)))
		{
			roptr[dir](stack_b, queue);
			while (stack_b->head->value >= stack_getmax(stack_a))
				stack_push(stack_b, stack_a, queue);
		}
	}
	push_main(stack_a, stack_b, queue);
}

void	push_main(t_stack *sta, t_stack *stb, t_queue *queue)
{
	void	(*roptr[2])(t_stack *, t_queue *);
	int		dir;

	roptr[0] = &stack_reverser;
	roptr[1] = &stack_rotate;
	if (stb->head->value <= sta->head->value)
	{
		if (stb->head->value < stack_getmin(sta))
		{
			dir = stack_getmindir(sta);
			while (sta->head->value > stack_getmin(sta))
				roptr[dir](sta, queue);
		}
		else
		{
			dir = st_bdir(stb->head->value, sta);
			while (!(stb->head->value > sta->head->prev->value \
			&& stb->head->value < sta->head->value))
				roptr[dir](sta, queue);
		}
		stack_push(stb, sta, queue);
	}
	else
		rotate_target(sta, stb, queue);
}

void	rotate_target(t_stack *sta, t_stack *stb, t_queue *queue)
{
	void	(*roptr[2])(t_stack *, t_queue *);
	int		dir;

	roptr[0] = &stack_reverser;
	roptr[1] = &stack_rotate;
	dir = st_bdir(stb->head->value, sta);
	while (!(stb->head->value < sta->head->value \
	&& stb->head->value > sta->head->prev->value))
		roptr[dir](sta, queue);
	stack_push(stb, sta, queue);
}

void	sort_checkhead(t_stack *sta, t_stack *stb, t_queue *queue, t_lim *lims)
{
	int		nxt;
	int		a_head;
	int		low;

	low = lims->low_lim;
	nxt = lims->next_lim;
	a_head = sta->head->value;
	if (sta->head->value > sta->head->next->value)
		if (stb->stack_size > 3 && stb->head->value < stb->head->next->value)
			stack_bothswap(sta, stb, queue);
	if (sta->head->value > sta->head->next->value)
		stack_swap(sta, queue);
	else
	{
		if (inlims(lims, sta))
			while (!(sta->head->value <= nxt && sta->head->value >= low))
				stack_rotate(sta, queue);
		if (stb->stack_size > 2 && a_head > lims->high_lim)
			if (a_head > stb->head->prev->value && queue->rotate_a < 0)
				stack_reverser(stb, queue);
		stack_push(sta, stb, queue);
		if (stack_getmin(stb) < lims->high_lim)
			while (stb->head != NULL && stb->head->value > lims->high_lim)
				stack_rotate(stb, queue);
	}
}
