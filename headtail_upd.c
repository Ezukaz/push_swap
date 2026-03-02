/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headtail_upd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 12:55:20 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/02 15:47:50 by Ezukaz           ###   ########.fr       */
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
 * @brief Decides whether head/tail needs to be updated
 * 
 * @param op Operation command
 * @param a Stack to update
 * @param b Stack to update
 */

void	ps_upd_bounds(const int op, t_stack *a, t_stack *b)
{
	if ((op == SB || op == SS) && (b->head_i == 0 || b->head_i == 1))
			upd_swap(b->head_i, b->tail_i, b->count);
	if ((op == SA || op == SS) && (a->head_i == 0 || a->head_i == 1))
			upd_swap(a->head_i, a->tail_i, a->count);
	if (op == RRB || op == RRR)
		upd_rotate(b, REVERSE);
	if (op == RRA || op == RRR)
		upd_rotate(a, REVERSE);
	if (op == RB || op == RR)
		upd_rotate(b, FORWARD);
	if (op == RA || op == RR)
		upd_rotate(a, FORWARD);
	if (op == PB)
		upd_push(b);
	if (op == PA)
		upd_push(a);
}
