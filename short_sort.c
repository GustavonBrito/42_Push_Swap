/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:42 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 13:57:40 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] > stack[i + 1] && i != size - 1)
			return (0);
		i++;
	}
	return (1);
}

void	short_sort(t_stack *stack)
{
	if (stack->size_stacks == 2)
		ra(stack);
	if (stack->size_stacks == 3)
		short_three(stack);
	if (stack->size_stacks == 4)
		short_four(stack);
	if (stack->size_stacks == 5)
		short_five(stack);
}
