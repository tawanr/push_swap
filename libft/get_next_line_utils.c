/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:44:01 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/27 10:52:51 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_gnl_bzero(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
		buffer[i++] = 0;
}

char	*ft_strnjoin(char *dst, char *src, int n)
{
	int		totallen;
	char	*output;
	int		i;

	i = 0;
	if (!dst)
		totallen = n;
	else
		totallen = ft_strlen(dst) + n;
	output = (char *)malloc((totallen + 1) * sizeof(char));
	while (dst && dst[i])
	{
		output[i] = dst[i];
		i++;
	}
	while (i < totallen)
	{
		output[i] = src[i - (totallen - n)];
		i++;
	}
	output[i] = '\0';
	if (dst)
		free(dst);
	return (output);
}

void	ft_gnl_lstdelone(t_storedlst **readlst, t_storedlst *target)
{
	t_storedlst	*temp;
	t_storedlst	*cur;

	cur = *readlst;
	if (*readlst == target)
	{
		free(target);
		*readlst = NULL;
		return ;
	}
	while (cur && cur->next != target)
		cur = cur->next;
	if (cur->next == target)
	{
		temp = cur->next;
		cur->next = temp->next;
		free(temp);
	}
	return ;
}

char	*ft_gnl_strdup(char *src)
{
	char	*output;
	int		i;

	i = 0;
	output = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	while (src[i] != '\0')
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
