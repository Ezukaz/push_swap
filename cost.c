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

static int	getb_pos(int n, t_stack b, t_endpoints ends)
{
	int	i;
	int	next;

	if (n > ends.head)
		return (ends.head_i);
	if (n < ends.tail)
		return ((ends.tail_i + 1) % b.count);
	i = 0;
	while (i < b.count)
	{
		next = (i + 1) % b.count;
		if ((n < b.stack[i]) && (n > b.stack[next]))
			return (next);
		i++;
	}
}

static t_cost	calc_cost(int a_i, int b_i, int a_dir, int b_dir)
{
	if (a_dir == REVERSE)
		;
}

t_cost	ps_lowest_cost()
{
	;
}
