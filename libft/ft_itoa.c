/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:30:17 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/15 21:30:17 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getdigit(unsigned int n);
int	ft_abs(int n);

char	*ft_itoa(int n)
{
	int				digit;
	int				negative;
	char			*out;
	int				i;
	unsigned int	num;

	negative = 0;
	num = (unsigned int)(ft_abs(n));
	if (n < 0)
		negative = 1;
	digit = getdigit(num);
	out = (char *)malloc((digit + negative + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = digit + negative;
	out[i--] = '\0';
	while (i >= negative)
	{
		out[i--] = '0' + (num % 10);
		num /= 10;
	}
	if (negative)
		out[0] = '-';
	return (out);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	getdigit(unsigned int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
