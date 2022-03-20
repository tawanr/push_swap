/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:55:22 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/20 14:42:11 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	findbreak(t_stack *stack, t_lim *limits, t_queue *queue)
{
	size_t	i;
	int		dir;
	void	(*roptr[2])(t_stack *, t_queue *);
	t_node	*temp;

	roptr[0] = &stack_reverser;
	roptr[1] = &stack_rotate;
	i = 0;
	temp = stack->head;
	while (!(temp->value <= limits->high_lim \
		&& temp->value >= limits->low_lim && \
		temp->prev->value < limits->low_lim))
	{
		temp = temp->next;
		i++;
	}
	dir = 1;
	if (i > stack->stack_size / 2)
		dir = 0;
	while (!(stack->head->value <= limits->high_lim \
		&& stack->head->value >= limits->low_lim && \
		stack->head->prev->value < limits->low_lim))
		roptr[dir](stack, queue);
}
