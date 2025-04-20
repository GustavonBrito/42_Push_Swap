/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:47 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 18:11:48 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_atol(char *str, t_stack *stack)
{
	int				sign;
	long long		result;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result *= sign;
	if (!(result >= -2147483648 && result <= 2147483647))
		stack->error_state = 1;
	return (result);
}

void	update_stack_b_for_push(int *stack_a, int *stack_b, int lenb, int lena)
{
	int	i;

	i = 0;
	while (stack_b[lenb -1])
	{
		stack_b[lenb] = stack_b[lenb -1];
		if (lenb -1 == 0)
			break ;
		lenb--;
	}
	stack_b[0] = stack_a[0];
	while (stack_a[i + 1])
	{
		stack_a[i] = stack_a[i + 1];
		if (i == lena -1)
			break ;
		i++;
	}
	stack_a[i] = 0;
}

void	ft_bzero_utils(t_stack *stack, size_t n)
{
	int	*p;

	p = stack->stack_b;
	while (n)
	{
		*p++ = 0;
		--n;
	}
}
