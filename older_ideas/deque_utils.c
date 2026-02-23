/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:50:07 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/19 13:55:45 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*dq_new_node(const int nbr)
{
	t_deque	*new_node;

	new_node = malloc(sizeof(t_deque));
	if (!new_node)
		return (NULL);
	new_node->data = nbr;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	dq_deqadd_back(t_endpoints **dq, t_deque *new_node)
{
	if (!dq || !new_node)
		return ;
	if (!*dq)
	{
		(*dq)->tail = new_node;
		return ;
	}
	(*dq)->tail->next = new_node;
	new_node->prev = (*dq)->tail;
}

void	dq_deqclear(t_deque **head)
{
	t_deque	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
