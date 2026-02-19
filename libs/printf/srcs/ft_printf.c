/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:10:45 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/19 15:32:47 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// !!ft_strchr("cspdiuxX%", c);
static int	is_specifier(const char current_c, const char next_c)
{
	return (current_c == '%' && (ft_strchr(SPECIFIERS, next_c) != NULL));
}

// Precondition: c must be valid (is_specifier does the check)
static int	call_specifier_fn(const unsigned char c, va_list ap)
{
	static t_fn_lookup	funcs[256];
	static int			flag;

	if (c == '%')
		return (write(1, "%", 1));
	if (!flag)
	{
		funcs['c'] = put_c;
		funcs['s'] = put_s;
		funcs['p'] = print_p;
		funcs['d'] = put_signed;
		funcs['i'] = put_signed;
		funcs['u'] = put_unsigned;
		funcs['x'] = print_lower_x;
		funcs['X'] = print_upper_x;
		flag = 1;
	}
	return (funcs[c](ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	va_start(args, format);
	count = 0;
	while (format[i] != '\0')
	{
		if (is_specifier(format[i], format[i + 1]))
		{
			count = verify_add(count, call_specifier_fn(format[i + 1], args));
			i++;
		}
		else
			count = verify_add(count, write(1, &format[i], 1));
		if (count == PRINT_ERR)
			break ;
		i++;
	}
	va_end(args);
	return (count);
}
