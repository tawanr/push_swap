/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:55:22 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/27 11:38:56 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_cleanup(t_stack *stack_a, t_stack *stack_b)
{
	stack_free(stack_a);
	stack_free(stack_b);
}

void	printerror(int *num_list)
{
	write(2, "Error\n", 6);
	if (num_list)
		free(num_list);
	exit (-1);
}
