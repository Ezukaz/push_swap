/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:24:56 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/24 00:40:59 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free, exit
# include <limits.h> // INT_MAX, INT_MIN
# define ERROR_STACK ((t_stack))

typedef struct s_stack
{
	int		stack[500];
	size_t	count;
}			t_stack;

long	my_atoi(const char *str);
t_stack	ps_parse(char **argv);
void	ps_operator(const char *op, t_stack *stack_a, t_stack *stack_b);
#endif