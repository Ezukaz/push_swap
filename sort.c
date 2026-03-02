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
	max = utl_max(a->stack, a->count);
	if (a->stack[0] == max)
		ps_perform_op(RA , a, NULL);
	else if (a->stack[1] == max)
		ps_perform_op(RRA , a, NULL);
	if (a->stack[0] > a->stack[1])
		ps_perform_op(SA , a, NULL);
}

void	ps_sort(t_stack *a, t_stack *b)
{
	int			i;
	t_min_cost	min;

	if (is_sorted(*a))
		return ;
	while (a->count > 3)
	{
		i = 0;
		while (i < a->count)
		{
			ps_compare_min(i, &min, *a, *b);
			i++;
		}
		ps_do_min(min, a, b);
	}
	tiny_sort(a);
	while (b->count > 0)
		ps_perform_op(PA, a, b);
	while (a->stack[0] != )
		ps_perform_op(RRA, a, b);
}
