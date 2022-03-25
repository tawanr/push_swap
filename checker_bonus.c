/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:58:33 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/23 08:57:20 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

//Init lists. Set list's head node.
//Check if list is already sorted.
//If not check logic and process.
int	main(int argc, char **argv)
{
	int		*num_list;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		check;

	num_list = (int *)malloc((argc - 1) * sizeof(int));
	if (argc <= 1)
		return (-1);
	if (!get_numarr(num_list, argv + 1, (size_t)argc - 1))
		return (-1);
	stack_a = init_stack(num_list, (size_t)argc - 1, 'a');
	stack_b = init_stack(NULL, 0, 'b');
	free(num_list);
	if (!stack_a || !stack_b)
		return (0);
	check = doop(stack_a, stack_b);
	if (check)
		printerror(num_list);
	check_stack(stack_a);
	ft_cleanup(stack_a, stack_b);
	return (0);
}

void	check_stack(t_stack *stack)
{
	int	sorted;

	sorted = checksort(stack);
	if (sorted == 1)
		ft_printf("OK");
	else
		ft_printf("KO");
}

int	doop(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;
	int		check;

	op = get_next_line(0);
	while (op)
	{
		if (ft_strncmp(op, "sa", 2) && ft_strlen(op) == 2)
			stack_swap(stack_a);
		else if (ft_strncmp(op, "sb", 2) && ft_strlen(op) == 2)
			stack_swap(stack_b);
		else if (ft_strncmp(op, "ss", 2) && ft_strlen(op) == 2)
			stack_bothswap(stack_a, stack_b);
		else if (ft_strncmp(op, "pa", 2) && ft_strlen(op) == 2)
			stack_push(stack_b, stack_a);
		else if (ft_strncmp(op, "pb", 2) && ft_strlen(op) == 2)
			stack_push(stack_a, stack_b);
		else
			check = doop_rotate(op, stack_a, stack_b);
		if (check)
			return (-1);
	}
	return (0);
}

int	doop_rotate(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(op, "rr", 2) && ft_strlen(op) == 2)
	{
		stack_rotate(stack_a);
		stack_rotate(stack_b);
	}
	else if (ft_strncmp(op, "ra", 2) && ft_strlen(op) == 2)
		stack_rotate(stack_a);
	else if (ft_strncmp(op, "rb", 2) && ft_strlen(op) == 2)
		stack_rotate(stack_b);
	else if (ft_strncmp(op, "rrr", 3) && ft_strlen(op) == 3)
	{
		stack_reverser(stack_a);
		stack_reverser(stack_b);
	}
	else if (ft_strncmp(op, "rra", 3) && ft_strlen(op) == 3)
		stack_reverser(stack_a);
	else if (ft_strncmp(op, "rrb", 3) && ft_strlen(op) == 3)
		stack_reverser(stack_b);
	else
		return (-1);
	return (0);
}
