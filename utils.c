/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:04:44 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/19 16:21:47 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Customized atoi 
 * 
 * @param str The string to convert
 * @return int The converted number
 * @note Validate the string is a number before passing to atoi
 */

long	my_atoi(const char *str)
{
	int		i;
	int		flag;
	long	result;

	i = 0;
	flag = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	result = 0;
	while (str[i])
	{
		result = 10 * result + (str[i] - '0');
		i++;
	}
	return (result * flag);
}

