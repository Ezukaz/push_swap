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

static int	is_sorted(t_stack stack)
{
	int	i;

	if (stack.count <= 1)
		return (1);
	i = 0;
	while (i < stack.count - 1)
	{
		if (stack.stack[i] > stack.stack[i + 1])
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
		ps_operator(RA , a, NULL);
	else if (a->stack[1] == max)
		ps_operator(RRA , a, NULL);
	if (a->stack[0] > a->stack[1])
		ps_operator(SA , a, NULL);
}

void	ps_sort(t_stack *a, t_stack *b)
{
	int			i;
	t_min_cost	min;

	while (a->count > 3)
	{
		i = 0;
		while (i < a.count)
		{
			ps_compare_min(i, &min, *a, *b);
			i++;
		}
		while ()
		ps_perform_op(, a, b);
	}
}
