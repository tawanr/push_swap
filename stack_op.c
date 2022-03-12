/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:37:18 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/22 15:50:51 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack *currstack)
{
	t_node	*temp;

	if (currstack->head == NULL)
		return ;
	temp = currstack->head->next;
	currstack->head->next = temp->next;
	temp->next->prev = currstack->head;
	currstack->head->prev->next = temp;
	temp->prev = currstack->head->prev;
	temp->next = currstack->head;
	currstack->head->prev = temp;
	currstack->head = temp;
	if (!DEBUG_MODE)
		ft_printf("s%c\n", currstack->name);
	return ;
}

void	stack_rotate(t_stack *currstack)
{
	if (currstack->head == NULL)
		return ;
	if (!DEBUG_MODE)
		ft_printf("r%c\n", currstack->name);
	currstack->head = currstack->head->next;
}

void	stack_reverser(t_stack *currstack)
{
	if (currstack->head == NULL)
		return ;
	if (!DEBUG_MODE)
		ft_printf("rr%c\n", currstack->name);
	currstack->head = currstack->head->prev;
}

void	stack_push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*temp;

	if (stack_from->head == NULL)
		return ;
	if (!DEBUG_MODE)
		ft_printf("p%c\n", stack_to->name);
	temp = stack_from->head;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	stack_from->head = temp->next;
	stack_from->stack_size--;
	if (stack_to->head == NULL)
	{
		stack_to->head = temp;
		temp->next = temp;
		temp->prev = temp;
		stack_to->stack_size++;
		return ;
	}
	temp->next = stack_to->head;
	temp->prev = stack_to->head->prev;
	stack_to->head = temp;
	temp->prev->next = temp;
	temp->next->prev = temp;
	stack_to->stack_size++;
	return ;
}