/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:57:52 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 12:57:54 by gustavo-lin      ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!strs)
		return (0);
	if (!ft_wordcount(s, c))
	{
		strs[0] = 0;
		return (strs);
	}
	return (ft_wordput(s, c, strs));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
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
