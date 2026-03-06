/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:05:39 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/06 18:21:54 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	error_stack;

	if (argc < 2)
		return (0);
	utl_init_stack(&error_stack);
	a = ps_parse(argv, error_stack);
	if (a.count == ERR_STACK)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	utl_init_stack(&b);
	ps_sort(&a, &b);
	return (0);
}
