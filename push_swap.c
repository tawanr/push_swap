/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:58:33 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/22 17:58:41 by tratanat         ###   ########.fr       */
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
	while (!(checksort(stack_a) && stack_a->stack_size == (size_t)argc - 1))
	{
		if (checksort(stack_a))
			while (stack_b->stack_size > 0)
			{
				sort_pushback(stack_a, stack_b);
				print_stacks(stack_a, stack_b, argc - 1);
			}
		else
			sort_checkhead(stack_a, stack_b);
		if (DEBUG_MODE)
			print_stacks(stack_a, stack_b, argc - 1);
	}
	while (stack_a->head->value != stack_getmin(stack_a))
		stack_rotate(stack_a);
	return (1);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b, size_t max_lines)
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
	usleep(REFRESH_RATE);
	system("clear");
	while (i++ < max_lines - max_stack)
		ft_printf("\n");
	i = 0;
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
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}