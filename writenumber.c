/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writenumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:16:20 by eates             #+#    #+#             */
/*   Updated: 2023/09/05 12:16:23 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writeint(int n, t_printf *x)
{
	int		arr[10];
	int		i;

	i = 0;
	if (!n)
		return (writechar('0', x));
	if (n == -2147483648)
		return (writestring("-2147483648", x));
	if (n < 0)
	{
		if (writechar('-', x) == -1)
			return (-1);
		n = -n;
	}
	while (n)
	{
		arr[i++] = n % 10;
		n /= 10;
	}
	while (i--)
		if (writechar(DECIMAL[arr[i]], x) == -1)
			return (-1);
	return (1);
}

int	writeuint(unsigned long n, t_printf *x)
{
	int		arr[16];
	int		i;

	i = 0;
	if (!n)
		return (writechar('0', x));
	while (n)
	{
		arr[i++] = n % 10;
		n /= 10;
	}
	while (i--)
		if (writechar(DECIMAL[arr[i]], x) == -1)
			return (-1);
	return (1);
}

int	writehex(unsigned long n, t_printf *x)
{
	int		arr[16];
	int		i;
	char	*hex;

	i = 0;
	if (!n)
		arr[i++] = 0;
	while (n)
	{
		arr[i++] = n % 16;
		n /= 16;
	}
	if (x->f == 'x')
		hex = HEXALOW;
	else
		hex = HEXAUP;
	while (i--)
		if (writechar(hex[arr[i]], x) == -1)
			return (-1);
	return (1);
}

int	writepoint(void *n, t_printf *x)
{
	int					arr[32];
	int					i;
	unsigned long long	nb;

	i = 0;
	nb = (unsigned long long)n;
	if (writestring("0x", x) == -1)
		return (-1);
	if (!nb)
		return (writechar('0', x));
	while (nb)
	{
		arr[i++] = nb % 16;
		nb /= 16;
	}
	while (i--)
		if (writechar(HEXALOW[arr[i]], x) == -1)
			return (-1);
	return (1);
}
