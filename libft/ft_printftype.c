/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:42:22 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/21 15:25:46 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printadd_hex(void *ptr)
{
	char	*out;
	int		printlen;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	printlen = 2;
	write(1, "0x", 2);
	out = ft_itoa_base((unsigned long)ptr, 16);
	ft_putstr_fd(out, 1);
	printlen += ft_strlen(out);
	free(out);
	return (printlen);
}

int	ft_printhex_low(int ptr)
{
	unsigned int	hex;
	int				negative_num;
	char			*result;
	int				length;

	negative_num = 0xFFFFFFFF;
	if (ptr < 0)
	{
		ptr = -ptr;
		hex = (unsigned int)((ptr ^ negative_num) + 1);
	}
	else
		hex = (unsigned int)ptr;
	result = ft_itoa_base(hex, 16);
	ft_putstr_fd(result, 1);
	length = ft_strlen(result);
	free(result);
	return (length);
}

int	ft_printhex_up(int ptr)
{
	unsigned int	hex;
	int				negative_num;
	char			*result;
	size_t			i;
	int				length;

	negative_num = 0xFFFFFFFF;
	if (ptr < 0)
	{
		ptr = -ptr;
		hex = (unsigned int)((ptr ^ negative_num) + 1);
	}
	else
		hex = (unsigned int)ptr;
	result = ft_itoa_base(hex, 16);
	i = 0;
	while (i < ft_strlen(result))
	{
		result[i] = ft_toupper(result[i]);
		i++;
	}
	ft_putstr_fd(result, 1);
	length = ft_strlen(result);
	free(result);
	return (length);
}

int	ft_putnbr_u(unsigned int n, int fd)
{
	char	*out;
	int		i;

	out = ft_itoa_u(n);
	i = ft_strlen(out);
	write(fd, out, i);
	free(out);
	return (i);
}
