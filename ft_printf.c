/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:16:43 by eates             #+#    #+#             */
/*   Updated: 2023/09/05 12:16:44 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	format(t_printf *x)
{
	if (x->f == 'c')
		return (writechar(va_arg(x->args, int), x));
	else if (x->f == 's')
		return (writestring(va_arg(x->args, char *), x));
	else if (x->f == 'd' || x->f == 'i')
		return (writeint(va_arg(x->args, int), x));
	else if (x->f == 'u')
		return (writeuint(va_arg(x->args, unsigned int), x));
	else if (x->f == 'p')
		return (writepoint(va_arg(x->args, void *), x));
	else if (x->f == 'x' || x->f == 'X')
		return (writehex(va_arg(x->args, unsigned int), x));
	else if (x->f == '%')
		return (writechar('%', x));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	t_printf	x;

	x.len = 0;
	va_start(x.args, s);
	while (*s++)
	{
		if (*(s - 1) == '%')
		{
			x.f = *s++;
			if (format(&x) == -1)
				return (va_end(x.args), -1);
		}
		else if (writechar(*(s - 1), &x) == -1)
			return (va_end(x.args), -1);
	}
	return (va_end(x.args), x.len);
}
