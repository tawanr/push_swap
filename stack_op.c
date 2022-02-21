/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:37:18 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/21 17:17:50 by tratanat         ###   ########.fr       */
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
	return ;
}

void	stack_rotate(t_stack *currstack)
{
	if (currstack->head == NULL)
		return ;
	currstack->head = currstack->head->next;
}

void	stack_reverser(t_stack *currstack)
{
	if (currstack->head == NULL)
		return ;
	currstack->head = currstack->head->prev;
}

void	stack_push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*temp;

	if (stack_from->head == NULL)
		return ;
	temp = stack_from->head;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	temp->next = NULL;
	temp->prev = NULL;
	stack_from->stack_size--;
	if (stack_to->head == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		return ;
	}
	temp->next = stack_to->head;
	temp->prev = stack_to->head->prev;
	temp->prev->next = temp;
	temp->next->prev = temp;
	stack_to->stack_size++;
	return ;
}