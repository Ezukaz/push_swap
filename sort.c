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

static void	insert_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	ps_operator("pb", &stack_a, &stack_b);
	i = 0;
	while (i < stack_a->count)
	{
		j = 0;
		while (j < stack_b->count)
		{
			if (stack_a->stack[i])
			j++;
		}
		i++;
	}
}
