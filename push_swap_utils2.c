/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:55:22 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/22 20:55:36 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_getarr(t_node *node, int max_size)
{
	int		i;
	t_node	*temp;
	int		*out;

	i = 0;
	out = (int *)malloc((max_size + 1) * sizeof(int));
	temp = node;
	while (i < max_size)
		out[i++] = temp->value;
}