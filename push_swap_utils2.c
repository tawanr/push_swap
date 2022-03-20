/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:55:22 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/20 18:45:15 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cleanup(t_stack *stack_a, t_stack *stack_b, t_queue *queue)
{
	flushqueue(-1, ' ', queue);
	stack_free(stack_a);
	stack_free(stack_b);
	free(queue);
}

void	stack_arrange(t_stack *stack_a, t_queue *queue)
{
	int		dir;

	dir = stack_getmindir(stack_a);
	while (stack_a->head->value != stack_getmin(stack_a))
	{
		if (dir == 1)
			stack_rotate(stack_a, queue);
		else
			stack_reverser(stack_a, queue);
	}
}

void	printerror(int *num_list)
{
	write(2, "Error\n", 6);
	free(num_list);
	exit (-1);
}
