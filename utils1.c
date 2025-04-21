/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:52 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 21:49:45 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_wordput(const char *s, char c, char **strs)
{
	size_t	j;
	size_t	i;
	size_t	flag;
	size_t	len;

	len = 0;
	flag = 1;
	j = 0;
	i = 0;
	while (s[j])
	{
		len = 0;
		while (s[j] == c)
			j++;
		while (s[j] && s[j] != c && ++len)
		{
			j++;
			flag = 1;
		}
		if (flag == 1)
			strs[i++] = ft_substr(s, j - len, len);
		flag = 0;
	}
	strs[i] = 0;
	return (strs);
}

void	bubble_sort(t_stack *stack, int n)
{
	int	temp;
	int	swapped;
	int	i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (stack->stack_b[i] > stack->stack_b[i + 1])
			{
				temp = stack->stack_b[i];
				stack->stack_b[i] = stack->stack_b[i + 1];
				stack->stack_b[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		n--;
	}
}
