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

static void	tiny_sort(t_stack *a)
{
	int	max;

	if (a->count < 2)
		return ;
	max = utl_max(a->stack, a->count);
	if (a->stack[0] == max)
		ps_operator("ra", a, NULL);
	else if (a->stack[1] == max)
		ps_operator("rra", a, NULL);
	if (a->stack[0] > a->stack[1])
		ps_operator("sa", a, NULL);
}

static void	insert_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	ps_operator("pb", a, b);
	i = 0;
	while (i < a->count)
	{
		j = 0;
		while (j < b->count)
		{
			if (a->stack[i])
			j++;
		}
		i++;
	}
}
