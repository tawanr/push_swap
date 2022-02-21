/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:05:52 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/21 17:17:38 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialize stack. Add all nodes from num_list.
// If size is zero, should return empty stack.
t_stack	*init_stack(int *num_list, size_t size, char name)
{
	t_stack	*stack;
	size_t	i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->stack_size = 0;
	stack->name = name;
	if (size == 0)
		return (stack);
	i = 0;
	while (i < size)
		if (!stack_appendnew(stack, num_list[i++]))
			return (NULL);
	return (stack);
}

// Append new node at end of stack.
int	stack_appendnew(t_stack *currstack, int num)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (0);
	if (currstack->stack_size == 0)
	{
		newnode->value = num;
		newnode->next = newnode;
		newnode->prev = newnode;
		currstack->head = newnode;
		currstack->stack_size++;
		return (1);
	}
	newnode->value = num;
	newnode->next = currstack->head;
	newnode->prev = currstack->head->prev;
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	currstack->stack_size++;
	return (1);
}

void stack_free(t_stack *currstack)
{
	size_t	stack_size;
	size_t	i;
	t_node	*temp;

	i = 0;
	stack_size = currstack->stack_size;
	while (i < stack_size)
	{
		temp = currstack->head->next;
		free(currstack->head);
		currstack->head = temp;
		i++;
	}
	free(currstack);
}