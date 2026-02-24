/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:24:56 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/24 15:47:55 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free, exit
# include <limits.h> // INT_MAX, INT_MIN
# define ERROR_STACK ((t_stack){0})

typedef struct s_stack
{
	int		stack[512];
	size_t	count;
}			t_stack;

long	my_atol(const char *str);
t_stack	ps_parse(char **argv);
void	ps_operator(const char *op, t_stack *stack_a, t_stack *stack_b);
#endif