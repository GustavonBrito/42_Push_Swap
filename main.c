/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:28:42 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/19 01:56:52 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(argv + 1, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!is_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}