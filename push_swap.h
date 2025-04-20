/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:56:29 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 22:14:49 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
	
	# include	"libft/headers/libft.h"
	# include	"libft/headers/ft_printf.h"
	# include	"libft/headers/get_next_line.h"
	# include	<stdbool.h>
	# include	<limits.h>
	
	typedef struct s_stack_node
	{
		int					nbr;
		int					index;
		int					push_cost;
		bool				above_median;
		bool				cheapest;
		struct s_stack_node	*target_node;
		struct s_stack_node	*next;
		struct s_stack_node	*prev;
	}	t_stack_node;

	

	
#endif