/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:58:33 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/21 17:30:03 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Init lists. Set list's head node.
//Check if list is already sorted.
//If not check logic and process.
int	main(int argc, char **argv)
{
	int		*num_list;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	size = argc - 1;
	num_list = (int *)malloc((argc - 1) * sizeof(int));
	if (argc <= 1)
		return (-1);
	if (!get_numarr(num_list, argv + 1, size))
		return (-1);
	stack_a = init_stack(num_list, size, 'a');
	stack_b = init_stack(NULL, 0, 'b');
	free(num_list);
	if (!stack_a || !stack_b)
		return (0);
	print_stacks(stack_a, stack_b);
	while (!(checksort(stack_a) && stack_a->stack_size == argc - 1))
	{
		if (checksort(stack_a))
		{
			while (stack_b->stack_size > 0)
				sort_pushback(stack_a, stack_b);
		}
		else
			sort_checkhead(stack_a, stack_b, stack_a->stack_size);
		//print_stacks(stack_a, stack_b);
	}
	while (stack_a->head->value != stack_getmin(stack_a))
		stack_rotate(stack_a);
	print_stacks(stack_a, stack_b);
	return (1);
}

int	sort_pushback(t_stack *stack_a, t_stack *stack_b)
{
	int	max_a;
	int	min_a;
	int max_b;

	max_a = stack_getmax(stack_a);
	min_a = stack_getmin(stack_a);
	max_b = stack_getmax(stack_b);
	while (stack_b->head->value != max_b)
		stack_rotate(stack_b);
	if (stack_getmax(stack_b) > max_a)
	{
		while (stack_a->head->prev->value != max_a)
			stack_rotate(stack_a);
		while (stack_b->head->value >= max_a)
			stack_push(stack_b, stack_a);
	}
	if (stack_a->stack_size <= 1)
		stack_push(stack_b, stack_a);
	else if (stack_b->head->value <= stack_a->head->value)
	{
		if (stack_b->head->value < min_a)
		{
			while (stack_a->head->value > min_a)
				stack_rotate(stack_a);
		}
		else
			while (stack_b->head->value < stack_a->head->prev->value)
				stack_reverser(stack_a);
		stack_push(stack_b, stack_a);
	}
	else
	{
		while (stack_b->head->value > stack_a->head->value)
			stack_rotate(stack_a);
		stack_push(stack_b, stack_a);
	}
	//print_stacks(stack_a, stack_b);
}

int	sort_checkhead(t_stack *stack_a, t_stack *stack_b, int max_size)
{
	if (stack_a->head->value > stack_a->head->next->value)
		stack_swap(stack_a);
	else if (stack_a->head->value > stack_a->head->prev->value)
	{
		stack_reverser(stack_a);
		write(1, "rra\n", 4);
	}
	else
	{
		if (stack_b->stack_size <= 2)
			stack_push(stack_a, stack_b);
		else if (stack_a->head->value >= stack_b->head->value)
		{
			if (stack_a->head->value > stack_getmax(stack_b))
				while (stack_b->head->value != stack_getmax(stack_b))
					stack_rotate(stack_b);
			else
				while (stack_a->head->value > stack_b->head->prev->value)
					stack_rotate(stack_b);
			stack_push(stack_a, stack_b);
		}
		else
		{
			if (!(stack_a->head->value < stack_getmin(stack_b)))
				while (stack_a->head->value < stack_b->head->value)
					stack_rotate(stack_b);
			else
				while (stack_b->head->value != stack_getmin(stack_b))
					stack_rotate(stack_b);
			if (!(stack_a->head->value > stack_getmax(stack_b)))
				while (stack_a->head->value > stack_b->head->prev->value)
					stack_reverser(stack_b);
			else
				while (stack_b->head->value != stack_getmax(stack_b))
					stack_rotate(stack_b);
			stack_push(stack_a, stack_b);
		}
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	size_t	max_stack;
	char	**out_a;
	char	**out_b;

	if (stack_a->stack_size >= stack_b->stack_size)
		max_stack = stack_a->stack_size;
	else
		max_stack = stack_b->stack_size;
	i = 0;
	out_a = get_stackarr(stack_a, max_stack);
	out_b = get_stackarr(stack_b, max_stack);
	printf("\n");
	while (i < max_stack)
	{
		printf("%s\t|\t%s\n", out_a[i], out_b[i]);
		i++;
	}
	ft_printf("-\t|\t-\na\t|\tb\n\n");
	freearr(out_a);
	freearr(out_b);
	return ;
}

void	freearr(char **arr)
{
	char	*temp;
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}