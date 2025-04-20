/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fon2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:33 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 18:13:21 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	i;
	int	first_number;
	int	len_b;

	ft_printf("%s", "ra\n");
	i = 0;
	len_b = 0;
	first_number = stack->stack_a[0];
	while (stack->stack_a[len_b])
		len_b++;
	while (i < len_b)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i -1] = first_number;
}

void	sort_three(t_stack *stack)
{
	int	max;
	int	med;

	med = (stack->stack_a[0] + stack->stack_a[1] + stack->stack_a[2]) / 3;
	max = med + 1;
	if (stack->stack_a[0] == max)
		ra(stack);
	if (stack->stack_a[0] == med)
		sa(stack);
	if (stack->stack_a[0] == max)
		ra(stack);
	if (!is_sorted(stack->stack_a, stack->size_stack_a))
		sa(stack);
	if (!is_sorted(stack->stack_a, stack->size_stack_a))
		ra(stack);
}

void	sort_four(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = stack->size_stacks;
	while (i < size)
	{
		if (stack->stack_a[0] == 1 || stack->stack_a[0] == 2)
			pb(stack->stack_a, stack->stack_b, stack);
		else
			ra(stack);
		i++;
	}
	if (!is_sorted(stack->stack_a, stack->size_stack_a))
		sa(stack);
	if (is_sorted(stack->stack_b, stack->size_stack_b))
		sb(stack);
	pa(stack->stack_b, stack->stack_a, stack);
	pa(stack->stack_b, stack->stack_a, stack);
}

void	sort_five(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = stack->size_stacks;
	while (i < size)
	{
		if (stack->stack_a[0] == 1 || stack->stack_a[0] == 2)
			pb(stack->stack_a, stack->stack_b, stack);
		else
			ra(stack);
		i++;
	}
	if (!is_sorted(stack->stack_a, stack->size_stack_a))
		sort_three(stack);
	if (is_sorted(stack->stack_b, stack->size_stack_b))
		sb(stack);
	pa(stack->stack_b, stack->stack_a, stack);
	pa(stack->stack_b, stack->stack_a, stack);
}
