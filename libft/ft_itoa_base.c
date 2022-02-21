/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:45:32 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/20 22:40:29 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	getdigit_base(unsigned long n, int base);
int	ft_abs_base(unsigned int n);

char	*ft_itoa_base(unsigned long num, int base)
{
	int				digit;
	char			*out;
	int				i;

	digit = getdigit_base(num, base);
	out = (char *)malloc((digit + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = digit;
	out[i--] = '\0';
	while (i >= 0)
	{
		if (num % base < 10)
			out[i--] = '0' + (num % base);
		else
			out[i--] = 'a' + ((num % base) % 10);
		num /= base;
	}
	return (out);
}

int	getdigit_base(unsigned long n, int base)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		digit++;
	}
	return (digit);
}
