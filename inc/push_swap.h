/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:24:56 by katakaha          #+#    #+#             */
/*   Updated: 2026/03/06 18:15:10 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free, exit
# include <limits.h> // INT_MAX, INT_MIN
# define FORWARD -1
# define REVERSE 1
# define ERR_STACK 0
# define ERR 1

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_op;

typedef struct s_stack
{
	int		stack[512];
	size_t	count;
	int		head_i;
	int		tail_i;
}			t_stack;

typedef struct s_args
{
	char	*args[512];
	size_t	count;
	int		err;
}			t_args;

typedef struct s_min_cost
{
	int	total;
	int	a;
	int	b;
}		t_min_cost;

typedef struct s_smallest3
{
	int	min1;
	int	min2;
	int	min3;
}		t_smallest3;

long	utl_atol(const char *str);
int		utl_max(const int *array, const size_t size, int *max_i);
int		utl_min(const int *array, const size_t size, int *min_i);
void	utl_init_min(t_min_cost *min);
void	utl_init_stack(t_stack *stack);
t_args	ps_arg_format(char **argv);
t_stack	ps_parse(char **argv, t_stack error);
void	ps_perform_op(const int op, t_stack *a, t_stack *b);
void	ps_compare_min(int a_pos, t_min_cost *min,	t_stack a, t_stack b);
void	ps_do_min(t_min_cost *min, t_stack *a, t_stack *b);
void	ps_sort(t_stack *a, t_stack *b);
#endif