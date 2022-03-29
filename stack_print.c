/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:51:56 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/29 23:13:59 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		line;
	int		max;
	t_node	*temp_a;
	t_node	*temp_b;

	usleep(100000);
	system("clear");
	line = 0;
	temp_a = stack_a->head;
	temp_b = stack_b->head;
	if (stack_a->stack_size > stack_b->stack_size)
		max = stack_a->stack_size;
	else
		max = stack_b->stack_size;
	while (line < max)
	{
		if (line >= max - stack_a->stack_size)
			printf("%4i", temp_a->value);
		else
			printf("    ");
		printf(" | ");
		if (line >= max - stack_b->stack_size)
			printf("%4i", temp_b->value);
		else
			printf("    ");
		printf("\n");
		line++;
	}
	printf("-----------\n");
	printf("  a  |  b  \n");
}