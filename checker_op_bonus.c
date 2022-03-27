/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:37:18 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/27 12:07:35 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	stack_bothswap(t_stack *sta, t_stack *stb)
{
	t_node	*temp;

	temp = sta->head->next;
	sta->head->next = temp->next;
	temp->next->prev = sta->head;
	sta->head->prev->next = temp;
	temp->prev = sta->head->prev;
	temp->next = sta->head;
	sta->head->prev = temp;
	sta->head = temp;
	temp = stb->head->next;
	stb->head->next = temp->next;
	temp->next->prev = stb->head;
	stb->head->prev->next = temp;
	temp->prev = stb->head->prev;
	temp->next = stb->head;
	stb->head->prev = temp;
	stb->head = temp;
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
	stack_from->head = temp->next;
	stack_from->stack_size--;
	if (stack_from->stack_size == 0)
		stack_from->head = NULL;
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
}
