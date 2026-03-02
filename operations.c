/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:31:11 by Ezukaz            #+#    #+#             */
/*   Updated: 2026/02/21 10:31:11 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
* @brief Forward or reverse rotation of stack depending on whether dest is
* @brief larger than src
*
* @param stack Stack to rotate
* @param dest Pointer to where you want to move(Eg.+ 1 from src for rev rot)
* @param src Pointer from where you want to move(Eg. + 1 from dest for fwd rot)
*
* @note If stack is NULL or contents of stack is less than 2, it will do nothing
*/

static void	rotation(t_stack *stack, int *dest, int *src)
{
	int	tmp;

	if (!stack || stack->count <= 1)
		return ;
	if (dest > src)
		tmp = stack->stack[stack->count - 1];
	else
		tmp = stack->stack[0];
	ft_memmove(dest, src, stack->count * sizeof(int));
	if (dest > src)
		stack->stack[0] = tmp;
	else
		stack->stack[stack->count - 1] = tmp;
	}

/**
 * @brief Push from top of stack to top of other stack
 * 
 * @param from_stack Stack to push from
 * @param to_stack Stack to push to
 * 
 * @note If either stack is NULL or from_stack is empty, it will do nothing
 */

static void	push(t_stack *from_stack, t_stack *to_stack)
{
	int	a_b;
	
	if (!from_stack || !to_stack || from_stack->count == 0)
		return ;
	a_b = from_stack->stack[0];
	ft_memmove(from_stack->stack,
		from_stack->stack + 1, from_stack->count * sizeof(int));
	--(from_stack->count);
	ft_memmove(to_stack->stack + 1, to_stack->stack,
		to_stack->count * sizeof(int));
	to_stack->stack[0] = a_b;
	++(to_stack->count);
}

/**
 * @brief Swap the first two elements of stack
 * 
 * @param stack Stack to swap
 * 
 * @note If stack is NULL or contents of stack are empty, it will do nothing
 */

static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->count <= 1)
		return ;
	tmp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = tmp;
}

/**
 * @brief Decides which helper to call on depending on what op is, and then
 * @brief prints op and updates bounds. ENUM for comparing op strings
 * 
 * @param op String with the operation command
 * @param a Stack A
 * @param b Stack B
 * 
 * @note Make sure op is valid
 */

void	ps_perform_op(const int op, t_stack *a, t_stack *b)
{
	size_t	op_len;

	if (op == SA || op == SS)
		swap(a);
	if (op == SB || op == SS)
		swap(b);
	if (op == PA)
		push(b, a);
	if (op == PB)
		push(a, b);
	if (op == RA || op == RR)
		rotation(a, a->stack, a->stack + 1);
	if (op == RB || op == RR)
		rotation(b, b->stack, b->stack + 1);
	if (op == RRA || op == RRR)
		rotation(a, a->stack + 1, a->stack);
	if (op == RRB || op == RRR)
		rotation(b, b->stack + 1, b->stack);
	ps_upd_bounds(op, a, b);
	op_len = ft_strlen(op);
	write(1, op, op_len);
	write(1, "\n", 1);
}

// #include <stdio.h>

// static void	print_stack(t_stack stack)
// {
// 	size_t	i = 0;
// 	while (i < stack.count)
// 	{
// 		printf("%d", stack.stack[i]);
// 		if (i < stack.count - 1)
// 			printf(",");
// 		i++;
// 	}
// 	printf(" | count = %lu\n", stack.count);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return (0);
// 	t_stack	a = ps_parse(argv);
// 	t_stack	b = {0};
// 	if (a.count == 0)
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}

// 	printf("origin:     ");
// 	print_stack(a);
// 	ps_operator("ra", &a, &b);
// 	ps_operator("ra", &a, &b);
// 	ps_operator("ra", &a, &b);
// 	ps_operator("ra", &a, &b);
// 	ps_operator("ra", &a, &b);
// 	printf("rotation A: ");
// 	print_stack(a);
// 	printf("rotation B: ");
// 	print_stack(b);
// 	ps_operator("pb", &a, &b); 
// 	ps_operator("pb", &a, &b);
// 	ps_operator("pb", &a, &b);
// 	ps_operator("pb", &a, &b);
// 	ps_operator("ra", &a, &b);
// 	ps_operator("rrb", &a, &b);
// 	ps_operator("rrb", &a, &b);
// 	ps_operator("rrb", &a, &b);
// 	printf("push A:     ");
// 	print_stack(a);
// 	printf("push B:     ");
// 	print_stack(b);
// 	ps_operator("sa", &a, &b);
// 	ps_operator("sb", &a, &b);
// 	ps_operator("pa", &a, &b);
// 	ps_operator("pa", &a, &b);
// 	ps_operator("pa", &a, &b);
// 	ps_operator("rrb", &a, &b);
// 	ps_operator("rrb", &a, &b);
// 	ps_operator("sb", &a, &b);
// 	ps_operator("sb", &a, &b);
// 	ps_operator("pa", &a, &b);
// 	ps_operator("pa", &a, &b);
// 	ps_operator("pa", &a, &b);
// 	ps_operator("pa", &a, &b);
// 	ps_operator("pa", &a, &b);
// 	ps_operator("rrb", &a, &b);
// 	ps_operator("rrb", &a, &b);
// 	ps_operator("rrb", &a, &b);
// 	ps_operator("sb", &a, &b);
// 	ps_operator("sb", &a, &b);
// 	ps_operator("sb", &a, &b);
// 	ps_operator("sb", &a, &b);
// 	printf("swap A:     ");
// 	print_stack(a);
// 	printf("swap B:     ");
// 	print_stack(b);
// 	return (0);
// }
