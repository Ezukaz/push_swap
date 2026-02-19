/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:24:56 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/19 16:59:16 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h> // write, read
#include <stdlib.h> // malloc, free, exit
#include <limits.h> // INT_MAX, INT_MIN

typedef struct s_deque
{
	struct s_deque	*next;
	struct s_deque	*prev;
	int		data;
}			t_deque;

typedef struct s_endpoints
{
	t_deque	*head;
	t_deque	*tail;
}			t_endpoints;

typedef struct s_stack
{
	int		stack[500];
	size_t	count;
}			t_stack;

long	my_atoi(const char *str);
t_deque	*dq_new_node(const int nbr);
void	dq_deqadd_back(t_endpoints **dq, t_deque *new_node);
void	dq_deqclear(t_deque **head);
t_stack	ps_parse(const char **argv, int argc);
#endif