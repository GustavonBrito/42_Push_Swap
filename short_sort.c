/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:49:49 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/21 11:27:48 by gserafio         ###   ########.fr       */
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
		sort_three(stack);
	if (stack->size_stacks == 4)
		sort_four(stack);
	if (stack->size_stacks == 5)
		sort_five(stack);
}
