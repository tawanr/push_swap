/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:51:38 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/20 20:09:00 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// op: 0 - reverse; 1 - rotate
void	addqueue(int op, char name, t_queue *queue)
{
	if (!op)
	{
		if (name == 'a')
			queue->rotate_a--;
		if (name == 'b')
			queue->rotate_b--;
	}
	else if (op == 1)
	{
		if (name == 'a')
			queue->rotate_a++;
		if (name == 'b')
			queue->rotate_b++;
	}
}

// op: 0 - swap; 1 - push; 2 - swap both
void	flushqueue(int op, char name, t_queue *queue)
{
	int			*rotate_a;
	int			*rotate_b;
	const char	op_type[2] = {'s', 'p'};

	rotate_a = &(queue->rotate_a);
	rotate_b = &(queue->rotate_b);
	while (queue->rotate_a > 0 && queue->rotate_b > 0)
	{
		queue->rotate_a--;
		queue->rotate_b--;
		ft_printf("rr\n");
	}
	while (queue->rotate_a < 0 && queue->rotate_b < 0)
	{
		queue->rotate_a++;
		queue->rotate_b++;
		ft_printf("rrr\n");
	}
	printrot(rotate_a, rotate_b);
	if (op == 2)
		ft_printf("ss\n");
	if (op != -1 && op != 2)
		ft_printf("%c%c\n", op_type[op], name);
}

void	printrot(int *rotate_a, int *rotate_b)
{
	while (*rotate_a != 0)
	{
		if (*rotate_a < 0)
		{
			(*rotate_a)++;
			ft_printf("rra\n");
			continue ;
		}
		(*rotate_a)--;
		ft_printf("ra\n");
	}
	while (*rotate_b != 0)
	{
		if (*rotate_b < 0)
		{
			(*rotate_b)++;
			ft_printf("rrb\n");
			continue ;
		}
		(*rotate_b)--;
		ft_printf("rb\n");
	}
}

t_queue	*initqueue(void)
{
	t_queue	*newqueue;

	newqueue = (t_queue *)malloc(sizeof(t_queue));
	newqueue->rotate_a = 0;
	newqueue->rotate_b = 0;
	return (newqueue);
}
