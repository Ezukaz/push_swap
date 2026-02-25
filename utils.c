/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:04:44 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/25 20:08:48 by katakaha         ###   ########.fr       */
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

long	utl_atol(const char *str)
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

int	utl_max_int(t_stack stack)
{
	int	max;
	int	i;

	max = INT_MIN;
	while (i < stack.count)
	{
		if (stack.stack[i] > max)
			max = stack.stack[i];
		i++;
	}
	return (max);
}

int	utl_min_int(t_stack stack)
{
	int	min;
	int	i;

	min = INT_MAX;
	while (i < stack.count)
	{
		if (stack.stack[i] < min)
			min = stack.stack[i];
		i++;
	}
	return (min);
}
