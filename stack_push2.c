/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:38:04 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/29 22:41:56 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inlimsback(t_lim *lims, t_stack *stack)
{
	t_node	*temp;
	int		i;
	int		inlim;

	temp = stack->head;
	inlim = 0;
	i = 0;
	while (i++ < stack->stack_size)
	{
		if (temp->value >= lims->low_lim && temp->value <= lims->next_lim)
			inlim++;
		temp = temp->next;
	}
	if (inlim > 0)
		return (1);
	return (0);
}

int	stack_getmaxlims(t_stack *stack, t_lim *lims)
{
	t_node	*temp;
	int		head_dir;
	int		tail_dir;

	temp = stack->head;
	head_dir = 0;
	tail_dir = 0;
	while (!(temp->value >= lims->low_lim && temp->value <= lims->next_lim))
	{
		temp = temp->next;
		head_dir++;
	}
	temp = stack->head;
	while (!(temp->value >= lims->low_lim && temp->value <= lims->next_lim))
	{
		temp = temp->prev;
		tail_dir++;
	}
	if (head_dir > tail_dir)
		return (0);
	return (1);
}

int	getmidlim(t_lim *lims, int sec)
{
	int	i;
	int	j;
	int	lowlim;
	int	uplim;

	i = 0;
	j = 0;
	if (sec == 0)
	{
		lowlim = lims->low_lim;
		uplim = lims->high_lim;
	}
	else if (sec == 1)
	{
		lowlim = lims->high_lim;
		uplim = lims->next_lim;
	}
	while (lims->arr[i] != lowlim)
		i++;
	j = i;
	while (lims->arr[j] != uplim)
		j++;
	return ((j - i) / 2);
}

void	check_sortlims(t_stack *sta, t_lim *lims)
{
	t_node	*temp;
	t_node	*pivot;

	pivot = sta->head;
	while (pivot->value != lims->high_lim)
		pivot = pivot->next;
	temp = pivot->next;
	while (nodeinlims(lims, temp, 1))
	{
		if (temp->value > pivot->value)
			temp->sorted = 1;
		else
			temp->sorted = 0;
	}
	temp = pivot->prev;
	while (nodeinlims(lims, temp, 0))
	{
		if (temp->value <= pivot->value)
			temp->sorted = 1;
		else
			temp->sorted = 0;
	}
}

void	splitlims(t_lim *lims, t_lim *lowlim, t_lim *uplim)
{
	uplim->low_lim = lims->high_lim;
	uplim->next_lim = lims->next_lim;
	uplim->high_lim = getmidlim(lims, 1);
	lowlim->low_lim = lims->low_lim;
	lowlim->next_lim = lims->high_lim;
	lowlim->high_lim = getmidlim(lims, 0);
}