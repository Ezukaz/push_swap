/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:03:57 by katakaha          #+#    #+#             */
/*   Updated: 2026/01/19 15:33:04 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	verify_add(int count, int write_res)
{
	if (write_res == PRINT_ERR)
		return (PRINT_ERR);
	return (write_res + count);
}

/*
POINTERS:
Is long safe? What is it for?

Long is not for INT_MIN overflow. Unsigned will handle that just fine. It is for
64-bit systems that have addresses that cannot fit in an int
This is safe because in a 64-bit system, long means long. Long only means int on
32-bit systems, and the addresses will fit in int, as well
65 for the max string size of a long
*/

int	print_unsigned_base(unsigned long ul, const char *base_chars)
{
	size_t	base;
	char	buf[65];
	int		i;
	int		char_count;

	if (!base_chars || base_chars[0] == '\0' || base_chars[1] == '\0')
		return (PRINT_ERR);
	base = ft_strlen(base_chars);
	i = 64;
	buf[i--] = '\0';
	if (ul == 0)
		buf[i--] = base_chars[0];
	while (ul > 0)
	{
		buf[i--] = base_chars[ul % base];
		ul /= base;
	}
	i++;
	char_count = 64 - i;
	return (write(1, buf + i, char_count));
}
