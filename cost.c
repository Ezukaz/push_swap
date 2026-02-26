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

static int	getb_pos(int n, t_stack b, int head)
{
	int	i;
	int	next;

	if (n > head)
		return (utl);
	i = 0;
	while (i < b->count)
	{
		next = (i + 1) % b->count;
		if ((n < b->stack[i]) && (n > b->stack[next]))
			return (next);
		i++;
	}
}

static calc_cost()
{
	;
}

t_cost	ps_lowest_cost()
{
	;
}
