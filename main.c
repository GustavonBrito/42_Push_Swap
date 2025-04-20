/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:23 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 18:08:16 by gustavo-lin      ###   ########.fr       */
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
		ft_printf("%s", "Error\n");
		return (-1);
	}
	if (!load_stack_from_input(stack, argv))
	{
		ft_printf("%s", "Error\n");
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

void	ft_double_sign(char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && argv[i][j + 1] == '-')
				|| (argv[i][j] == '+' && argv[i][j + 1] == '+'))
			{
				stack->error_state = 1;
			}
			j++;
		}
		i++;
	}
}
