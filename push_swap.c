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
	if (argc <= 1 || !get_numarr(num_list, argv + 1, size))
	{
		write(2, "Error\n", 6);
		free(num_list);
		return (-1);
	}
	printf("got numarr\n");
	stack_a = init_stack(num_list, size);
	printf("got stack a\n");
	stack_b = init_stack(NULL, 0);
	free(num_list);
	//if (!stack_a || !stack_b)
		//return (0);
	//if (checksort(stack_a))
		//return (1);
	ft_printf("printing stacks:\n\n");
	print_stacks(stack_a, stack_b);
	/*
	sort_stack(stack_a, stack_b);
	if (checksort())
	print_stacks(stack_a, stack_b);
	*/
	return (1);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	size_t	max_stack;
	char	**out_a;
	char	**out_b;

	printf("stack_a size: %li stack_b size: %li\n", stack_a->stack_size, stack_b->stack_size);
	if (stack_a->stack_size >= stack_b->stack_size)
		max_stack = stack_a->stack_size;
	else
		max_stack = stack_b->stack_size;
	printf("max_stack: %li\n", max_stack);
	i = 0;
	out_a = get_stackarr(stack_a, max_stack);
	out_b = get_stackarr(stack_b, max_stack);
	while (i < max_stack)
	{
		ft_printf("%s\t|\t%s\n", out_a[i], out_b[i]);
		i++;
	}
	ft_printf("-\t|\t-\na\t|\tb\n");
	//freearr(out_a);
	//freearr(out_b);
	return ;
}

char	**get_stackarr(t_stack *stack, size_t max_stack)
{
	size_t		i;
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
	return (out);
}

int	checksort(t_stack *currstack)
{
	size_t		i;
	t_node	*temp;

	i = 0;
	temp = currstack->head->next;
	ft_printf("current stack_size: %i\n", currstack->stack_size);
	while (i++ < currstack->stack_size - 1)
	{
		ft_printf("checking %i and %i\n", temp->value, temp->prev->value);
		if (!(temp->value >= temp->prev->value))
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	get_numarr(int *num_list, char **charlist, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!checknum(charlist[i]))
			return (0);
		num_list[i] = ft_atoi(charlist[i]);
		i++;
	}
	return (1);
}

int	checknum(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}