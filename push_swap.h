/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:24:56 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/27 13:50:22 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free, exit
# include <limits.h> // INT_MAX, INT_MIN
# define ERROR_STACK ((t_stack){0})
# define FORWARD 1
# define REVERSE -1

typedef struct s_stack
{
	int		stack[512];
	size_t	count;
}			t_stack;

typedef struct s_cost
{
	int		total;
	int		a;
	int		b;
}			t_cost;

typedef struct s_endpoints
{
	int		head;
	int		head_i;
	int		tail;
	int		tail_i;
}			t_endpoints;

long	utl_atol(const char *str);
int		utl_max(const int *array, const size_t size);
int		utl_min(const int *array, const size_t size);
int		utl_inarray(const int val, const t_stack array);
t_stack	ps_parse(char **argv);
void	ps_operator(const char *op, t_stack *a, t_stack *b);
void	ps_upd_ends(t_stack b, t_endpoints *ends, const char *op);
#endif