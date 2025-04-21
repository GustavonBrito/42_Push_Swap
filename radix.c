/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:38 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/21 08:01:17 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max_value;
	int	max_bit;
	int	i;

	i = 0;
	max_value = 0;
	while (i < stack->size_stacks)
	{
		if (stack->stack_a[i] > max_value)
			max_value = stack->stack_a[i];
		i++;
	}
	if (max_value < 0)
		max_value = -max_value;
	max_bit = 0;
	while (max_value > 0)
	{
		max_value >>= 1;
		max_bit++;
	}
	return (max_bit);
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	size;
	int	j;

	size = get_max_bits(stack);
	i = 0;
	stack->size_stack_a = 0;
	stack->size_stack_b = 0;
	while (i < size)
	{
		j = 0;
		while (j < stack->size_stacks)
		{
			if ((stack->stack_a[0] >> i) & 1)
				ra(stack);
			else
				pb(stack->stack_a, stack->stack_b, stack);
			j++;
		}
		i++;
		while (!is_stack_b_empty(stack))
			pa(stack->stack_b, stack->stack_a, stack);
	}
}

int	is_stack_b_empty(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->stack_b[i])
		i++;
	if (i != 0)
		return (0);
	return (1);
}
