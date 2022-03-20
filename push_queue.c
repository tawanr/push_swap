/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:51:38 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/20 12:01:12 by tratanat         ###   ########.fr       */
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

// op: 0 - swap; 1 - push
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
		if (!DEBUG_MODE)
			printf("rr\n");
	}
	while (queue->rotate_a < 0 && queue->rotate_b < 0)
	{
		queue->rotate_a++;
		queue->rotate_b++;
		if (!DEBUG_MODE)
			printf("rrr\n");
	}
	while (*rotate_a != 0)
	{
		if (*rotate_a < 0)
		{
			(*rotate_a)++;
			if (!DEBUG_MODE)
				printf("rra\n");
		}
		else
		{
			(*rotate_a)--;
			if (!DEBUG_MODE)
				printf("ra\n");
		}
	}
	while (*rotate_b != 0)
	{
		if (*rotate_b < 0)
		{
			(*rotate_b)++;
			if (!DEBUG_MODE)
				printf("rrb\n");
		}
		else
		{
			(*rotate_b)--;
			if (!DEBUG_MODE)
				printf("rb\n");
		}
	}
	if (op != -1 && !DEBUG_MODE)
		printf("%c%c\n", op_type[op], name);
}

t_queue	*initqueue(void)
{
	t_queue	*newqueue;

	newqueue = (t_queue *)malloc(sizeof(t_queue));
	newqueue->rotate_a = 0;
	newqueue->rotate_b = 0;
	return (newqueue);
}
