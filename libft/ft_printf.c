/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:17:37 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/21 15:25:43 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		length;

	length = 0;
	va_start(arg_ptr, str);
	while (*str)
	{
		if (*str == '%')
			length += ft_printarg(*(++str), arg_ptr);
		else
		{
			write(1, str, 1);
			length++;
		}
		str++;
	}
	va_end(arg_ptr);
	return (length);
}

int	ft_printarg(const char flag, va_list arg_ptr)
{
	if (flag == 'c')
	{
		ft_putchar_fd(va_arg(arg_ptr, int), 1);
		return (1);
	}
	else if (flag == 's')
		return (ft_putstr_fd(va_arg(arg_ptr, char *), 1));
	else if (flag == 'p')
		return (ft_printadd_hex(va_arg(arg_ptr, void *)));
	else if (flag == 'd' || flag == 'i')
		return (ft_putnbr_fd(va_arg(arg_ptr, int), 1));
	else if (flag == 'u')
		return (ft_putnbr_u(va_arg(arg_ptr, unsigned int), 1));
	else if (flag == 'x')
		return (ft_printhex_low(va_arg(arg_ptr, int)));
	else if (flag == 'X')
		return (ft_printhex_up(va_arg(arg_ptr, int)));
	else if (flag == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
