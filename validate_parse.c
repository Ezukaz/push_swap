/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:43:54 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/19 16:59:41 by katakaha         ###   ########.fr       */
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
 * @brief Checks if int then checks if there are no duplicates. Only then will
 * @brief it add to the validated array. NULL means error. Parent must handle.
 * @brief Does not handle no arguments. Parent must handle.
 * 
 * @param argv Input arguments
 * @param argc Argument count
 * @return int* The validated ints in an array or NULL
 */

t_stack	ps_parse(const char **argv, int argc)
{
	int			conv;
	int			i;
	size_t		count;
	t_stack		stack_a;

	i = 1;
	count = 0;
	stack_a.count = 0;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (stack_a);
		conv = my_atoi(argv[i]);
		if (!no_duplicate(stack_a.stack, conv, count))
			return (stack_a);
		stack_a.stack[count] = conv;
		count++;
		i++;
	}
	stack_a.count = count;
	return (stack_a);
}

size_t test_clean(int argc, const char **argv){
	return (ps_parse(argv, argc).count);
}

int main(int argc, const char **argv){
	size_t	res;
	if ((res = test_clean(argc, argv)))
		printf("Pass\n");
	else
		printf("Fail\n");
	return (0);
}
