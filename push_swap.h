/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:58:35 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/20 22:33:30 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/headers/libft.h"
# include "libft/headers/ft_printf.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		size_stacks;
	int		error_state;
	int		size_stack_a;
	int		size_stack_b;
}	t_stack;

int		load_stack_from_input(t_stack *stack, char **argv);
char	**ft_split(char const *s, char c);
char	**ft_wordput(const char *s, char c, char **strs);
int		ft_wordcount(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	init_space_arg(t_stack *stack, char **argv);
size_t	ft_atol(char *str, t_stack *stack);
void	initialize_stack_index(t_stack *stack);
void	update_stack_b_for_push(int *stack_a, int *stack_b, int lenb, int lena);
int		pa(int *stack_a, int *stack_b, t_stack *stack);
int		pb(int *stack_a, int *stack_b, t_stack *stack);
void	sb(t_stack *stack);
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	bubble_sort(t_stack *stack, int n);
void	ft_bzero_utils(t_stack *stack, size_t n);
void	radix_sort(t_stack *stack);
int		get_max_bits(t_stack *stack);
int		is_empty(t_stack *stack);
int		is_sorted(int *stack, int size);
void	short_sort(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack);
void	sort_five(t_stack *stack);
void	swap_for_p(int *stack_a, int *stack_b, int lena);
int		check_doubles(t_stack *stack);
void	ft_double_sign(char **argv, t_stack *stack);
void	ft_free_split(char **temp);
void	ft_chracter_check(char **argv, t_stack *stack);

#endif