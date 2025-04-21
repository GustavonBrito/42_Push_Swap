/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:50:18 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/21 13:34:59 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size_stacks)
	{
		j = i + 1;
		while (j < stack->size_stacks)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				return (1);
			j++;
		}
	}
	return (0);
}

void	ft_free_split(char **temp)
{
	int	i;

	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
}

static int	ft_is_valid_argument(char *arg)
{
	int	i;
	int	found_digit;

	i = 0;
	found_digit = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			found_digit = 1;
		else if (arg[i] == '-' || arg[i] == '+' || arg[i] == 32
			|| arg[i] == '\t')
		{
			if (!(((arg[i + 1] >= '0' && arg[i + 1] <= '9')
						&& !(arg[i - 1] >= '0' && arg[i - 1] <= '9'))
					|| arg[i] == 32 || arg[i] == '\t'))
				return (0);
		}
		else
			return (0);
		i++;
	}
	if (!found_digit)
		return (0);
	return (1);
}

void	ft_chracter_check(char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_is_valid_argument(argv[i]))
		{
			stack->error_state = 1;
			return ;
		}
	}
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
