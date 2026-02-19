/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:12:49 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/16 19:11:02 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PRINT_ERR -1
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define BASE_10 "0123456789"
# define SPECIFIERS "cspdiuxX%"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h> // For uintptr_t

typedef int	(*t_fn_lookup)(va_list);

int	ft_printf(const char *format, ...);
int	put_c(va_list ap);
int	put_s(va_list ap);
int	put_signed(va_list ap);
int	put_unsigned(va_list ap);
int	print_lower_x(va_list ap);
int	print_upper_x(va_list ap);
int	print_p(va_list ap);
int	print_unsigned_base(unsigned long ud, const char *base_chars);
int	verify_add(int count, int write_res);

#endif
