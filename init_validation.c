/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:58:41 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 19:35:32 by gustavo-lin      ###   ########.fr       */
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

void	ft_free_temp(char **temp)
{
	int	i;

	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
}

void	ft_chracter_check(char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				continue ;
			else if (argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == 32)
			{
				if (((argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
						&& !(argv[i][j - 1] >= '0' && argv[i][j - 1] <= '9'))
					|| (argv[i][j] == 32))
					continue ;
				else
					stack->error_state = 1;
			}
			else
				stack->error_state = 1;
		}
	}
}
