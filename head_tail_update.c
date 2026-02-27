/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_tail_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 12:55:20 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/27 13:21:34 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	upd_swap(int *end_i)
{
	*end_i = ((*end_i) + 1) % 2;
}

static void	upd_rotate(t_stack b, t_endpoints *ends, int dir)
{
	ends->head_i = (ends->head_i + b.count + dir) % b.count;
	ends->tail_i = (ends->tail_i + b.count + dir) % b.count;
}

static void	upd_push(t_stack b, t_endpoints *ends)
{
		if (b.stack[0] > ends->head)
		{
			ends->head = b.stack[0];
			ends->head_i = 0;
			ends->tail_i++;
		}
		else if (b.stack[0] < ends->tail)
		{
			ends->tail = b.stack[0];
			ends->tail_i = 0;
			ends->head_i++;
		}
		else
		{
			ends->head_i++;
			ends->tail_i++;
		}
}

void	ps_upd_ends(t_stack b, t_endpoints *ends, const char *op)
{
	if (!ft_strncmp(op, "sb", 2) || !ft_strncmp(op, "ss", 2))
	{
		if (ends->head_i == 0 || ends->head_i == 1)
			upd_swap(&ends->head_i);
		else if (ends->tail_i == 0 || ends->tail_i == 1)
			upd_swap(&ends->tail_i);
	}
	if (!ft_strncmp(op, "rrb", 3) || !ft_strncmp(op, "rrr", 3))
		upd_rotate(b, ends, 1);
	if (!ft_strncmp(op, "rb", 2) || !ft_strncmp(op, "rr", 2))
		upd_rotate(b, ends, -1);
	if (!ft_strncmp(op, "pb", 2))
		upd_push(b, ends);
}
