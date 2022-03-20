/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:05:23 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/20 10:08:36 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getsortedarr(t_stack *stack, int **array)
{
	int		low;
	int		high;
	size_t	i;
	t_node	*temp;

	i = 0;
	low = 0;
	high = stack->stack_size - 1;
	*array = (int *)malloc(stack->stack_size * sizeof(int));
	temp = stack->head;
	while (i < stack->stack_size)
	{
		(*array)[i] = temp->value;
		temp = temp->next;
		i++;
	}
	recursivesort(*array, low, high);
	// for (size_t i = 0; i < stack->stack_size; i++)
	// 	printf("array[%ld]: %i\n", i, (*array)[i]);
	return (stack->stack_size);
}

void	recursivesort(int *array, int low, int high)
{
	int	index;

	if (low < high)
	{
		index = quicksort(array, low, high);
		recursivesort(array, low, index - 1);
		recursivesort(array, index + 1, high);
	}
}

int	quicksort(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	j = low;
	i = j - 1;
	pivot = array[high];
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
				ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	if (i + 1 != high)
		ft_swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
