/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fon1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:28 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 14:58:21 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	argc;
	int	b;

	write(1, "sa\n", 3);
	argc = 0;
	while (stack->stack_a[argc])
		argc++;
	if (argc >= 2)
	{
		b = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = b;
	}
}

void	sb(t_stack *stack)
{
	int	argc;
	int	b;

	write(1, "sb\n", 3);
	argc = 0;
	while (stack->stack_a[argc])
		argc++;
	if (argc >= 2)
	{
		b = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = b;
	}
}

int	pb(int *stack_a, int *stack_b,	t_stack *stack)
{
	int	i;
	int	lena;
	int	lenb;

	stack->size_stack_a -= 1;
	stack->size_stack_b += 1;
	write(1, "pb\n", 3);
	i = 0;
	lenb = 0;
	lena = 0;
	while (stack_b[i++])
		lenb++;
	i = 0;
	while (stack_a[i++])
		lena++;
	if (lena == 0)
		return (1);
	i = 0;
	if (lenb == 0)
		swap_for_p(stack_a, stack_b, lena);
	else
		edit_b_for_pb(stack_a, stack_b, lenb, lena);
	return (1);
}

void	swap_for_p(int *stack_a, int *stack_b, int lena)
{
	int	i;

	i = 0;
	stack_b[0] = stack_a[0];
	while (stack_a[i + 1])
	{
		stack_a[i] = stack_a[i + 1];
		if (i == lena -1)
			break ;
		i++;
	}
	stack_a[i] = 0;
}

int	pa(int *stack_a, int *stack_b, t_stack *stack)
{
	int	i;
	int	lena;
	int	lenb;

	write(1, "pa\n", 3);
	stack->size_stack_a += 1;
	stack->size_stack_b -= 1;
	i = 0;
	lenb = 0;
	lena = 0;
	while (stack_b[i++])
		lenb++;
	i = 0;
	while (stack_a[i++])
		lena++;
	if (lena == 0)
		return (1);
	i = 0;
	if (lenb == 0)
		swap_for_p(stack_a, stack_b, lena);
	else
		edit_b_for_pb(stack_a, stack_b, lenb, lena);
	return (1);
}
