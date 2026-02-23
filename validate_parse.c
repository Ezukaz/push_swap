/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:43:54 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/23 17:09:01 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	has_whitespace(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

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
	overflow_check = my_atoi(str);
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
 * @brief Explodes arguments with spaces, and adds all arguments to an array
 * 
 * @param char** Input args
 * @return t_stack Input args correctly formatted into a struct array with count
 *
 * @note Must validate there is input before passing
 */

static char	**arg_format(char **argv)
{
	char	**split_args;
	char	**res;
	int		i;
	int		count;

	res = malloc(500 * sizeof(char *));
	if (!res)
		return (NULL);
	i = 1;
	count = 0;
	while (argv[i])
	{
		if (has_whitespace(argv[i]))
		{
			split_args = ft_split(argv[i]);
			if (!split_args)
				return (NULL);
			while (*split_args)
				res[count++] = *split_args++;
		}
		else
			res[count++] = argv[i];
		i++;
	}
	res[count] = NULL;
	return (res);
}

/**
 * @brief Checks if int then checks if there are no duplicates. Only then will
 * @brief it add to the validated array. 0 count means invalid array. Parent must handle.
 * @brief Does not handle no arguments. Parent must handle.
 * 
 * @param argv Input arguments
 * @param argc Argument count
 * @return t_stack Validated struct which contains ints in an array and the count of values in the array. Count stays 0 until all arguments are validated.
 */

t_stack	ps_parse(char **argv)
{
	int			conv;
	int			i;
	char		**stack_a;
	t_stack		sanitized_a;

	i = 0;
	sanitized_a.count = 0;
	stack_a = arg_format(argv);
	if (!stack_a)
		return (ERROR_STACK);
	while (stack_a[i])
	{
		if (!is_int(stack_a[i]))
			return (ERROR_STACK);
		conv = my_atoi(stack_a[i]);
		if (!no_duplicate(sanitized_a.stack, conv, sanitized_a.count))
			return (ERROR_STACK);
		sanitized_a.stack[sanitized_a.count++] = conv;
		i++;
	}
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
