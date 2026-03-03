/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:30:07 by Ezukaz            #+#    #+#             */
/*   Updated: 2026/02/24 00:30:07 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief A beginning check to see if we need to sort
 * 
 * @param a Stack_a
 * @return int True or false
 */

static int	is_sorted(t_stack a)
{
	int	i;

	if (a.count <= 1)
		return (1);
	i = 0;
	while (i < a.count - 1)
	{
		if (a.stack[i] > a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Sorts <=3 elements in an array
 * @brief I use this for larger arrays by pushing out until the last 3 are left
 * 
 * @param a Stack_a, as this will only used for stack_a
 *
 * @note I can make this to be scalable, but maybe later
 */

static void	tiny_sort(t_stack *a)
{
	int	max;

	if (a->count <= 1)
		return ;
	max = utl_max(a->stack, a->count, 0);
	if (a->stack[0] == max)
		ps_perform_op(RA , a, NULL);
	else if (a->stack[1] == max)
		ps_perform_op(RRA , a, NULL);
	if (a->stack[0] > a->stack[1])
		ps_perform_op(SA , a, NULL);
}

/**
 * @brief Get the 3 smallest values in the array
 * 
 * @param a Array to check
 * @param min3 Struct with three vars for each of the smallest values
 *
 * @note Find the smallest value from a copy array of the original, and then
 * @note erase it from the array so that we can look for the next smallest
 */

static void	get_3min(t_stack a, t_smallest3 *min3)
{
	int	i;

	min3->min1 = utl_min(a.stack, a.count, &i);
	ft_memmove(a.stack + i, a.stack + i + 1, a.count);
	a.count--;
	min3->min2 = utl_min(a.stack, a.count, &i);
	ft_memmove(a.stack + i, a.stack + i + 1, a.count);
	a.count--;
	min3->min3 = utl_min(a.stack, a.count, &i);
	ft_memmove(a.stack + i, a.stack + i + 1, a.count);
	a.count--;
}

/**
 * @brief Total of six steps to sort a stack
 * 
 * @param a Stack to sort
 * @param b Temporary stack to store values
 *
 * @note 1. Check if it is sorted
 * @note 2. Get the 3 smallest values
 * @note 3. Loop till we only have 3 values in stack_a
 * @note 	For each loop, loop through every value to find the least amount of
 * @note 		moves, and skip it if it is one of the 3 smallest
 * @note 4. Once we get to the last 3, tiny_sort those 3
 * @note 5. Push all of stack_b back into stack_a
 * @note 6. Last, rotate stack_a 3 times to get it to the right position
 */

void	ps_sort(t_stack *a, t_stack *b)
{
	int			i;
	t_min_cost	min;
	t_smallest3	sm3;

	if (is_sorted(*a))
		return ;
	get_3min(*a, &sm3);
	while (a->count > 3)
	{
		i = 0;
		while (i < a->count)
		{
			if (a->stack[i] != sm3.min1
				&& a->stack[i] != sm3.min2
				&& a->stack[i] != sm3.min3)
				ps_compare_min(i, &min, *a, *b);
			i++;
		}
		ps_do_min(min, a, b);
	}
	tiny_sort(a);
	while (b->count > 0)
		ps_perform_op(PA, a, b);
	while (a->stack[0] != sm3.min1)
		ps_perform_op(RRA, a, b);
}
