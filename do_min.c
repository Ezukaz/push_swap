/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:33:56 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/02 22:52:31 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	symmetrical_rotation(t_min_cost *min, t_stack *a, t_stack *b)
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

static void	asymmetrical_rotation(t_min_cost *min, t_stack *a, t_stack *b)
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

void	ps_do_min(t_min_cost min, t_stack *a, t_stack *b)
{
	while (min.a || min.b)
	{
		if (min.a * min.b > 0)
			symmetrical_rotation(&min, a, b);
		else
			asymmetrical_rotation(&min, a, b);
	}
	ps_perform_op(PB, a, b);
}
