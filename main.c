/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:28:42 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 00:50:43 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	// if (!parse_args(argv + 1, &a))
	// {
	// 	write(2, "Error\n", 6);
	// 	return (1);
	// }
	// if (!is_sorted(a))
	// 	sort_stack(&a, &b);
	// free_stack(&a);
	return (0);
}