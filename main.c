/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:23 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 19:54:23 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
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
