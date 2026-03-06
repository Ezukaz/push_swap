/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:43:54 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/06 18:20:00 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief Int checker
 * 
 * @param str The string to check
 * @return int True or false
 * @note Check for NULL input
 * @note Skip leading '-' or '+'
 * @note Check for empty input (no digits)
 * @note Check for only digits or only digits after leading '-' or '+'
 */

static int	is_int(const char *str)
{
	size_t	i;
	long	overflow_check;

	if (!str)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (0);
	++i;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	overflow_check = utl_atol(str);
	if (overflow_check > INT_MAX || overflow_check < INT_MIN)
		return (0);
	return (1);
}

/**
 * @brief Checks for duplicates
 * 
 * @param args The array with validated numbers
 * @param arg The number to check if there is a duplicate
 * @param count The number of ints in the array
 * @return int True or false
 */

static int	no_duplicate(const int *args, const int arg, const size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (args[i] == arg)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Safely frees the contents of an array (strings)
 * 
 * @param array Array with contents that needs to be freed
 */

static void	free_all(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
}

/**
 * @brief Checks if int then checks if there are no duplicates. Only then will
 * @brief it add to the validated array. 0 count means invalid array. Parent
 * @brief must handle.
 * @brief Does not handle no arguments. Parent must handle.
 * 
 * @param argv Input arguments
 * @param error Empty stack to signal error
 * @return t_stack Validated struct which contains ints in an array and the
 * @return count of values in the array. On error, an empty struct is returned
 */

t_stack	ps_parse(char **argv, t_stack error)
{
	int		conv;
	int		i;
	t_args	a;
	t_stack	sanitized_a;

	i = 0;
	utl_init_stack(&sanitized_a);
	a = ps_arg_format(argv);
	if (a.err)
		return (free_all(a.args), error);
	while (a.args[i] != NULL)
	{
		if (!is_int(a.args[i]))
			return (free_all(a.args), error);
		conv = utl_atol(a.args[i]);
		if (!no_duplicate(sanitized_a.stack, conv, sanitized_a.count))
			return (free_all(a.args), error);
		sanitized_a.stack[sanitized_a.count++] = conv;
		i++;
	}
	i = 0;
	free_all(a.args);
	return (sanitized_a);
}

// #include <stdio.h>

// size_t test_clean(char **argv){
// 	return (ps_parse(argv).count);
// }

// int main(int argc, char **argv){
// 	size_t	res;
// 	if (argc < 2)
// 		return (0);
// 	if ((res = test_clean(argv)))
// 		printf("Pass: %lu\n", res);
// 	else
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	return (0);
// }
