/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:05:07 by eates             #+#    #+#             */
/*   Updated: 2023/09/05 13:07:09 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# if defined(__APPLE__)
#  define LOCATION 1
# elif defined(__linux__)
#  define LOCATION 2
# endif
# include <stdarg.h>
# include <stdint.h>

# define DECIMAL "0123456789"
# define HEXALOW "0123456789abcdef"
# define HEXAUP "0123456789ABCDEF"

typedef struct s_printf
{
	va_list		args;
	char		f;
	int			len;
}		t_printf;

int		writechar(char c, t_printf *x);
int		writestring(char *s, t_printf *x);
int		writeint(int n, t_printf *x);
int		writeuint(unsigned long n, t_printf *x);
int		writepoint(void *n, t_printf *x);
int		writehex(unsigned long n, t_printf *x);
int		ft_printf(const char *s, ...);

#endif
