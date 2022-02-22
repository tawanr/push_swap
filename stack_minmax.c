/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:57:47 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/21 23:31:05 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_minnode(t_stack *currstack)
{
	t_node	*temp;
	size_t	i;
	t_node	*min_node;

	if (currstack == NULL || currstack->stack_size <= 0)
		return (NULL);
	temp = currstack->head;
	min_node = NULL;
	i = 0;
	while (i++ < currstack->stack_size)
	{
		if (min_node == NULL || min_node->value > temp->value)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}

t_node	*stack_maxnode(t_stack *currstack)
{
	t_node	*temp;
	size_t	i;
	t_node	*max_node;

	if (currstack == NULL || currstack->stack_size <= 0)
		return (NULL);
	temp = currstack->head;
	max_node = NULL;
	i = 0;
	while (i++ < currstack->stack_size)
	{
		if (max_node == NULL || max_node->value < temp->value)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}

int	stack_getmin(t_stack *currstack)
{
	t_node	*temp;
	size_t	i;
	t_node	*min_node;

	if (currstack == NULL || currstack->stack_size <= 0)
		return (-1);
	temp = currstack->head;
	min_node = NULL;
	i = 0;
	while (i++ < currstack->stack_size)
	{
		if (min_node == NULL || min_node->value > temp->value)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node->value);
}

int	stack_getmax(t_stack *currstack)
{
	t_node	*temp;
	size_t	i;
	t_node	*max_node;

	if (currstack == NULL || currstack->stack_size <= 0)
		return (-1);
	temp = currstack->head;
	max_node = NULL;
	i = 0;
	while (i++ < currstack->stack_size)
	{
		if (max_node == NULL || max_node->value < temp->value)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node->value);
}