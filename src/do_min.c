/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:33:56 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/06 13:14:25 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates both stacks in the same direction
 * 
 * @param min Gives the direction of rotation
 * @param a Stack_a to rotate
 * @param b Stack_b to rotate
 */

static void	symmetrical_rot(t_min_cost *min, t_stack *a, t_stack *b)
{
	if (min->a < 0 && min->b < 0)
	{
		ps_perform_op(RR, a, b);
		min->a++;
		min->b++;
	}
	else if (min->a > 0 && min->b > 0)
	{
		ps_perform_op(RRR, a, b);
		min->a--;
		min->b--;
	}
}

/**
 * @brief Does single rotations for any direction
 * 
 * @param min Gives the direction of rotation
 * @param a Stack_a to rotate
 * @param b Stack_b to rotate
 */

static void	asymmetrical_rot(t_min_cost *min, t_stack *a, t_stack *b)
{
	if (min->a > 0)
	{
		ps_perform_op(RRA, a, b);
		min->a--;
	}
	if (min->a < 0)
	{
		ps_perform_op(RA, a, b);
		min->a++;
	}
	if (min->b > 0)
	{
		ps_perform_op(RRB, a, b);
		min->b--;
	}
	if (min->b < 0)
	{
		ps_perform_op(RB, a, b);
		min->b++;
	}
}

/**
 * @brief Executes the rotations that the min struct is storing
 * 
 * @param min Struct with the cheapest moves. Controls how many moves left to do
 * @param a Stack_a with numbers that we want to move to stack_b
 * @param b Stack_b receives numbers from stack_a, and puts them in order
 *
 * @note The last if statement is for an edge case. When there is only one value
 * @note 	in stack_b, we cannot adjust to the right position by rotating. So
 * @note 	we push, and then see if we need to realign it by rotating it once
 */

void	ps_do_min(t_min_cost *min, t_stack *a, t_stack *b)
{
	while (min->a || min->b)
	{
		if (min->a * min->b > 0)
			symmetrical_rot(min, a, b);
		else
			asymmetrical_rot(min, a, b);
	}
	ps_perform_op(PB, a, b);
	if (b->count == 2 && b->stack[0] < b->stack[1])
		ps_perform_op(SB, a, b);
	min->total = INT_MAX;
}
