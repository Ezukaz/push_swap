/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:20:48 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/19 19:52:13 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief Pushes and pops a stack. dir will be 'd'(down) or 'u'(up). Down will
 * @brief push the top and pop it into the bottom. Up is a reverse.
 * 
 * @param stack The stack to rotate.
 * @param dir The direction of the rotation.
 */
 
void	rotate(t_stack *stack, char dir)
{
	int	tmp;

	if (dir == 'd')
	{
		tmp = stack->stack[0];
		ft_memmove(stack->stack, stack->stack + 1, stack->count);
	}
}

void	push(int *stack1, int *stack2)
{
	
}

void	swap(int *stack)
{
	
}