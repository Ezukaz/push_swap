/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:05:39 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/04 17:27:04 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_stack(t_stack *stack)
{
	stack->count = 0;
	stack->head_i = 0;
	stack->tail_i = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	a = ps_parse(argv);
	if (a.count == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stack(&b);
	ps_sort(&a, &b);
	size_t	i = 0;
	while (i < a.count)
	{
		printf("%d ", a.stack[i]);
		i++;
	}
	printf("\n");
	return (0);
}
