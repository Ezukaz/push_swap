/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:43:29 by Ezukaz            #+#    #+#             */
/*   Updated: 2026/02/26 23:43:29 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief Get b_pos by checking where n from a fits in stack_b
 * 
 * @param a_n A number from stack_a
 * @param b Struct for stack_b
 * @return int New head or new tail, or the correct pos somewhere in-between
 *
 * @note Just gets the pos for a_n if we were to move it in stack_b but nothing
 * @note is decided yet
 */

static int	getb_pos(int a_n, t_stack b)
{
	int	i;
	int	next;

	if (a_n > b.stack[b.head_i])
		return (b.head_i);
	if (a_n < b.stack[tail_i])
		return ((b.tail_i + 1) % b.count);
	i = 0;
	while (i < b.count)
	{
		next = (i + 1) % b.count;
		if ((a_n < b.stack[i]) && (a_n > b.stack[next]))
			return (next);
		i++;
	}
}

/**
 * @brief Finds the cost for opposing directions or same direction
 * 
 * @param a_cost Cost for moving a_pos to the top of stack_a
 * @param b_cost Cost for moving b_pos to the top of stack_b
 * @param a_dir Direction for moving a_pos. REVERSE is 1, FORWARD is -1
 * @param b_dir Direction for moving b_pos
 * @return t_min_cost Struct with the costs of a&b and their total.
 * @return If dir is negative, cost of a or b becomes negative, too
 */

static t_min_cost	get_cost(int a_cost, int b_cost, int a_dir, int b_dir)
{
	t_min_cost	costs;
	int			total;

	if (a_dir + b_dir)
		total = ult_max((int[]){a_cost, b_cost}, 2);
	else
		total = a_cost + b_cost;
	costs.total = total;
	costs.a = a_cost * a_dir;
	costs.b = b_cost * b_dir;
	return (costs);
}

/**
 * @brief Updates the lowest cost if lower is found
 * 
 * @param a_pos Index of n from stack_a
 * @param min Struct with the current lowest cost and a&b's cost(sign for dir)
 * @param a Stack_a
 * @param b Stack_b with head/tail information
  */

void	ps_lowest_cost(int a_pos, t_min_cost *min,	t_stack a, t_stack b)
{
	t_min_cost	tmp;
	int			b_pos;

	b_pos = getb_pos(a.stack[a_pos], b);
	tmp = get_cost(a.count - a_pos, b.count - b_pos, REVERSE, REVERSE);
	if (tmp.total < min->total)
		*min = tmp;
	tmp = get_cost(a.count - a_pos, b_pos, REVERSE, FORWARD);
	if (tmp.total < min->total)
		*min = tmp;
	tmp = get_cost(a_pos, b.count - b_pos, FORWARD, REVERSE);
	if (tmp.total < min->total)
		*min = tmp;
	tmp = get_cost(a_pos, b_pos, FORWARD, FORWARD);
	if (tmp.total < min->total)
		*min = tmp;
}
