/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:49:22 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/21 11:27:56 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	if (argc < 1)
	{
		write(2, "Error\n", 7);
		return (-1);
	}
	if (!load_stack_from_input(stack, argv))
	{
		write(2, "Error\n", 7);
		return (-1);
	}
	if (!is_sorted(stack->stack_a, stack->size_stacks))
	{
		if (stack->size_stacks <= 5)
			short_sort(stack);
		else
			radix_sort(stack);
	}
	return (free(stack->stack_b), free(stack->stack_a), free(stack), 0);
}
