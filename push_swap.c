/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:58:33 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/20 15:47:53 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Init lists. Set list's head node.
//Check if list is already sorted.
//If not check logic and process.
int	main(int argc, char **argv)
{
	int		*num_list;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_queue	*queue;
	int		dir;

	queue = initqueue();
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
	dosort(stack_a, stack_b, queue, (size_t)argc - 1);
	dir = stack_getmindir(stack_a);
	while (stack_a->head->value != stack_getmin(stack_a))
	{
		if (dir == 1)
			stack_rotate(stack_a, queue);
		else
			stack_reverser(stack_a, queue);
	}
	flushqueue(-1, ' ', queue);
	if (DEBUG_MODE)
		print_stacks(stack_a, stack_b, argc - 1);
	free(queue);
	return (0);
}

void	dosort(t_stack *stack_a, t_stack *stack_b, t_queue *queue, size_t size)
{
	static t_lim	limits = {0, 0, 0};
	int				arr_size;
	int				*array;
	int				div;

	arr_size = getsortedarr(stack_a, &array);
	div = 1;
	if (arr_size > 50 && arr_size <= 200)
		div = arr_size / 15;
	else if (arr_size > 200)
		div = arr_size / 25;
	getlims(&limits, array, div, arr_size);
	while (!(checksort(stack_a) && stack_a->stack_size == size))
	{
		if (!inlims(&limits, stack_a))
			getlims(&limits, array, div, arr_size);
		if (checksort(stack_a))
		{
			while (stack_b->stack_size > 0)
			{
				sort_pushback(stack_a, stack_b, queue);
				if (DEBUG_MODE)
					print_stacks(stack_a, stack_b, size);
			}
		}
		else
			sort_checkhead(stack_a, stack_b, queue, &limits);
		if (DEBUG_MODE)
			print_stacks(stack_a, stack_b, size);
	}
}

void	getlims(t_lim *limits, int *array, int div, int arr_size)
{
	static int	count = 0;

	count++;
	if (count == div)
	{
		limits->low_lim = array[0];
		limits->high_lim = array[arr_size - 1];
		limits->next_lim = limits->high_lim;
	}
	else if (count == 1)
	{
		limits->low_lim = array[(int)((count - 1) * (float)(arr_size / div))];
		limits->high_lim = array[(int)((float)(count * (arr_size / div))) - 1];
		limits->next_lim = limits->high_lim;
		if (!(count > div - 2))
			limits->next_lim = array[(int)((float)((count + 1) * (arr_size / div))) - 1];
	}
	else
	{
		limits->low_lim = limits->high_lim;
		limits->high_lim = array[(count * (arr_size / div)) - 1];
		limits->next_lim = limits->high_lim;
		if (!(count > div - 2))
			limits->next_lim = array[(int)((float)((count + 1) * (arr_size / div))) - 1];
	}
}

int	inlims(t_lim *limits, t_stack *stack_a)
{
	t_node	*temp;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	temp = stack_a->head;
	while (i < stack_a->stack_size)
	{
		if (temp->value <= limits->high_lim && temp->value >= limits->low_lim)
			count++;
		temp = temp->next;
		i++;
	}
	if (count > 0)
		return (1);
	else
		return (0);
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
