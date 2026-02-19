/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:43:54 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/17 21:01:10 by katakaha         ###   ########.fr       */
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

static int	no_duplicate(int *args, int arg, size_t count)
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

int	*ps_validation(char **argv, int argc)
{
	static int	clean_nums[500];
	int			conv;
	int			i;
	size_t		count;

	i = 0;
	count = 0;
	while (i < argc)
	{
		if (is_int(argv[i]))
		{
			conv = my_atoi(argv[i]);
			if (!no_duplicate(clean_nums, conv, count))
				return (NULL);
			clean_nums[count] = conv;
			count++;
		}
		i++;
	}
	return (clean_nums);
}

int test_dup(void) {
	int arr[] = {1,2,3,4};
	return (no_duplicate(arr, 4, 4));
}

int main(void) {
	if (test_dup())
		printf("Pass\n");
	else
		printf("Fail\n");
	return (0);
}