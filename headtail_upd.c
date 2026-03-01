/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_headtail_upd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 12:55:20 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/02 05:18:41 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief Change index of head. Change tail only if count is 2
 * 
 * @param stack Swapped stack
 * @param count Number of elements in stack
 */

static void	upd_swap(t_stack stack, int count)
{
	stack->head_i = (stack->head_i + 1) % 2;
	if (count == 2)
		stack->tail_i = (stack->tail_i + 1) % 2;
}

/**
 * @brief Change index for head&tail
 * 
 * @param stack Rotated stack
 * @param dir Direction of rotation
 *
 * @note (n + dir) % count will make index rotate forward if dir is positive.
 * @note If we want to go back, we must be careful that the index does not
 * @note become negative. To avoid this, we add count. This way it will never
 * @note become negative.
 */

static void	upd_rotate(t_stack *stack, int dir)
{
	stack->head_i = (stack->head_i + stack->count + dir) % stack->count;
	stack->tail_i = (stack->tail_i + stack->count + dir) % stack->count;
}

/**
 * @brief Update index of head&tail
 * 
 * @param stack Pushed stack
 *
 * @note If pushed val is new head/tail then head/tail index is 0. Otherwise,
 * @note increment head and/or tail
 */

static void	upd_push(t_stack *stack)
{
		if (stack->stack[0] > stack->stack[stack->head_i])
		{
			stack->head_i = 0;
			stack->tail_i++;
		}
		else if (stack->stack[0] < stack->stack[stack->tail_i])
		{
			stack->tail_i = 0;
			stack->head_i++;
		}
		else
		{
			stack->head_i++;
			stack->tail_i++;
		}
}

/**
 * @brief Decides what to update
 * 
 * @param stack Stack to update
 * @param op Operation command
 */

void	ps_upd_ends(t_stack *stack, const char *op)
{
	if (!ft_strncmp(op, "sb", 2) || !ft_strncmp(op, "ss", 2))
	{
		if (stack->head_i == 0 || stack->head_i == 1)
			upd_swap(stack->head_i, stack->tail_i, stack->count);
	}
	if (!ft_strncmp(op, "rrb", 3) || !ft_strncmp(op, "rrr", 3))
		upd_rotate(stack, REVERSE);
	if (!ft_strncmp(op, "rb", 2) || !ft_strncmp(op, "rr", 2))
		upd_rotate(stack, FORWARD);
	if (!ft_strncmp(op, "pb", 2))
		upd_push(stack);
}
