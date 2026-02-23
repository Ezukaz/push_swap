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
* @brief Forward or reverse rotation of stack depending on whether dest is larger than src
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
	ft_memmove(from_stack->stack, from_stack->stack + 1, from_stack->count * sizeof(int));
	--(from_stack->count);
	ft_memmove(to_stack->stack + 1, to_stack->stack, to_stack->count * sizeof(int));
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
 * @brief Decides which helper to call on depending on what op is, and then writes op
 * 
 * @param op String with the operation command
 * @param stack_a Stack A
 * @param stack_b Stack B
 * 
 * @note Make sure op is valid
 */

void	ps_operator(const char *op, t_stack *stack_a, t_stack *stack_b)
{
	size_t	op_len;

	if (op == "sa" || op == "ss")
		swap(&stack_a);
	if (op == "sb" || op == "ss")
		swap(&stack_b);
	if (op == "pa")
		push(&stack_b, &stack_a);
	if (op == "pb")
		push(&stack_a, &stack_b);
	if (op == "ra" || op == "rr")
		rotation(&stack_a, &stack_a, &stack_a + 1);
	if (op == "rb" || op == "rr")
		rotation(&stack_b, &stack_b, &stack_b + 1);
	if (op == "rra" || op == "rrr")
		rotation(&stack_a, &stack_a + 1, &stack_a);
	if (op == "rb" || op == "rrr")
		rotation(&stack_b, &stack_b + 1, &stack_b);
	op_len = strlen(op);
	write(1, &op, op_len);
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
// 	t_stack	stack_a = ps_parse(argv);
// 	t_stack	stack_b = {0};
// 	if (stack_a.count == 0)
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}

// 	printf("origin:     ");
// 	print_stack(stack_a);
// 	rotation(&stack_a, &stack_a.stack[1], &stack_a.stack[0]);
// 	rotation(&stack_a, &stack_a.stack[1], &stack_a.stack[0]);
// 	rotation(&stack_a, &stack_a.stack[1], &stack_a.stack[0]);
// 	rotation(&stack_a, &stack_a.stack[1], &stack_a.stack[0]);
// 	rotation(&stack_a, &stack_a.stack[1], &stack_a.stack[0]);
// 	printf("rotation A: ");
// 	print_stack(stack_a);
// 	printf("rotation B: ");
// 	print_stack(stack_b);
// 	push(&stack_a, &stack_b);
// 	push(&stack_a, &stack_b);
// 	push(&stack_a, &stack_b);
// 	push(&stack_a, &stack_b);
// 	rotation(&stack_a, &stack_a.stack[1], &stack_a.stack[0]);
// 	rotation(&stack_b, &stack_b.stack[0], &stack_b.stack[1]);
// 	rotation(&stack_b, &stack_b.stack[0], &stack_b.stack[1]);
// 	rotation(&stack_b, &stack_b.stack[0], &stack_b.stack[1]);
// 	printf("push A:     ");
// 	print_stack(stack_a);
// 	printf("push B:     ");
// 	print_stack(stack_b);
// 	swap(&stack_a);
// 	swap(&stack_b);
// 	push(&stack_b, &stack_a);
// 	push(&stack_b, &stack_a);
// 	push(&stack_b, &stack_a);
// 	rotation(&stack_b, &stack_b.stack[0], &stack_b.stack[1]);
// 	rotation(&stack_b, &stack_b.stack[0], &stack_b.stack[1]);
// 	swap(&stack_b);
// 	swap(&stack_b);
// 	push(&stack_b, &stack_a);
// 	push(&stack_b, &stack_a);
// 	push(&stack_b, &stack_a);
// 	push(&stack_b, &stack_a);
// 	push(&stack_b, &stack_a);
// 	rotation(&stack_b, &stack_b.stack[0], &stack_b.stack[1]);
// 	rotation(&stack_b, &stack_b.stack[0], &stack_b.stack[1]);
// 	rotation(&stack_b, &stack_b.stack[0], &stack_b.stack[1]);
// 	swap(&stack_b);
// 	swap(&stack_b);
// 	swap(&stack_b);
// 	swap(&stack_b);
// 	printf("swap A:     ");
// 	print_stack(stack_a);
// 	printf("swap B:     ");
// 	print_stack(stack_b);
// 	return (0);
// }
