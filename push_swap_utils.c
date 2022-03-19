/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:40:13 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/19 05:26:29 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_stackarr(t_stack *stack, size_t max_stack)
{
	size_t	i;
	char	**out;
	t_node	*temp;

	i = 0;
	out = (char **)malloc((max_stack + 1) * sizeof(char *));
	temp = stack->head;
	while (i < max_stack)
	{
		if (stack->stack_size < max_stack - i)
		{
			out[i] = (char *)malloc(2 * sizeof(char));
			*(out[i]) = ' ';
			*(out[i] + 1) = '\0';
		}
		else
		{
			out[i] = ft_itoa(temp->value);
			temp = temp->next;
		}
		i++;
	}
	out[max_stack] = NULL;
	return (out);
}

int	checksort(t_stack *currstack)
{
	size_t	i;
	t_node	*temp;

	i = 0;
	if (currstack->stack_size <= 1)
		return (1);
	temp = stack_minnode(currstack)->next;
	while (i++ < currstack->stack_size - 1)
	{
		if (!(temp->value >= temp->prev->value))
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	checkrevsort(t_stack *currstack)
{
	size_t	i;
	t_node	*temp;

	i = 0;
	if (currstack->stack_size <= 1)
		return (1);
	temp = stack_maxnode(currstack)->next;
	while (i++ < currstack->stack_size - 1)
	{
		if (!(temp->value <= temp->prev->value))
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	get_numarr(int *num_list, char **charlist, int size)
{
	int	i;
	int	current;
	int	j;

	i = 0;
	while (i < size)
	{
		if (!checknum(charlist[i]) || ft_strlen(charlist[i]) > 11)
		{
			write(2, "Error\n", 6);
			free(num_list);
			return (0);
		}
		current = ft_atoi(charlist[i]);
		j = 0;
		while (j < i)
		{
			if (num_list[j] == current)
			{
				write(2, "Error\n", 6);
				free(num_list);
				return (0);
			}
			j++;
		}
		num_list[i] = ft_atoi(charlist[i]);
		i++;
	}
	return (1);
}

int	checknum(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str) || *str == '+' || *str == '-'))
			return (0);
		str++;
	}
	return (1);
}