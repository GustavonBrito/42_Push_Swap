/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:18 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 14:58:01 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_size_calculate(char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**temp;

	i = 0;
	count = 0;
	while (argv[++i])
	{
		if (have_space(argv[i]))
		{
			temp = ft_split(argv[i], 32);
			j = -1;
			while (temp[++j])
			{
				count++;
			}
			ft_free_temp(temp);
		}
		else
			count++;
	}
	i = 0;
	return (count);
}

int	have_space(char *arguman)
{
	int	i;

	i = -1;
	while (arguman[++i])
	{
		if (arguman[i] == 32)
			return (1);
	}
	return (0);
}

int	init_stack_data(t_stack *stack, char **argv)
{
	stack->size_stacks = argv_size_calculate(argv);
	stack->stack_a = ft_calloc(stack->size_stacks + 1, sizeof(int));
	if (!stack->stack_a)
		return (0);
	stack->stack_b = ft_calloc(stack->size_stacks + 1, sizeof(int));
	if (!stack->stack_b)
	{
		free(stack->stack_a);
		return (0);
	}
	stack->error_state = 0;
	stack->size_stack_a = stack->size_stacks;
	stack->size_stack_b = 0;
	init_space_arg(stack, argv);
	ft_double_sign(argv, stack);
	ft_chracter_check(argv, stack);
	if (stack->error_state == 1)
		return (0);
	if (check_doubles(stack))
		return (0);
	init_index(stack);
	return (1);
}

void	init_index(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_stacks)
	{
		stack->stack_b[i] = stack->stack_a[i];
		i++;
	}
	bubble_sort(stack, stack->size_stacks);
	i = -1;
	while (++i < stack->size_stacks)
	{
		j = -1;
		while (++j < stack->size_stacks)
		{
			if (stack->stack_a[i] == stack->stack_b[j])
			{
				stack->stack_a[i] = j + 1;
				break ;
			}
		}
	}
	ft_bzero(stack, stack->size_stacks);
}

void	init_space_arg(t_stack *stack, char **argv)
{
	int		i;
	int		j;
	int		stack_index;
	char	**temp;

	i = 0;
	stack_index = 0;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) == 0 || argv[i] == NULL)
			stack->error_state = 1;
		if (have_space(argv[i]))
		{
			temp = ft_split(argv[i], 32);
			j = -1;
			while (temp[++j])
			{
				stack->stack_a[stack_index] = ft_atoi(temp[j], stack);
				stack_index++;
			}
			ft_free_temp(temp);
		}
		else
			stack->stack_a[stack_index++] = ft_atoi(argv[i], stack);
	}
}
