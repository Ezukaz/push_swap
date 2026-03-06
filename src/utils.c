/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:04:44 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/06 15:38:15 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Customized atoi 
 * 
 * @param str The string to convert
 * @return int The converted number
 *
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

/**
 * @brief Finds the largest number of an array
 * 
 * @param array Array with ints
 * @param size Size of the array
 * @param max_i Pointer of int to store the index of the largest value
 * @param max_i You can pass NULL if you don't need the index
 * @return int Max value of array
 *
 * @note Make sure array is initialized
 */

int	utl_max(const int *array, const size_t size, int *max_i)
{
	size_t	i;
	int		max;

	i = 0;
	max = array[0];
	if (max_i)
		*max_i = 0;
	while (i < size)
	{
		if (array[i] > max)
		{
			max = array[i];
			if (max_i)
				*max_i = i;
		}
		i++;
	}
	return (max);
}

/**
 * @brief Finds the smallest number of an array
 * 
 * @param array Array with ints
 * @param size Size of the array
 * @param min_i Pointer of int to store the index of the smallest value
 * @param min_i You can pass NULL if you don't need the index
 * @return int Smallest value of array
 *
 * @note Make sure array is initialized
 */

int	utl_min(const int *array, const size_t size, int *min_i)
{
	size_t	i;
	int		min;

	i = 0;
	min = array[0];
	if (min_i)
		*min_i = 0;
	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
			if (min_i)
				*min_i = i;
		}
		i++;
	}
	return (min);
}

/**
 * @brief Initiates the values of t_cost_min struct
 * 
 * @param min Declared struct
 */

void	utl_init_min(t_min_cost *min)
{
	min->total = INT_MAX;
	min->a = 0;
	min->b = 0;
}

void	utl_init_stack(t_stack *stack)
{
	stack->count = 0;
	stack->head_i = 0;
	stack->tail_i = 0;
}
