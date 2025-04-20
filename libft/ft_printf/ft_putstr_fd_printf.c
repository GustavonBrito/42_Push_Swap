/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:35:51 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/20 19:50:39 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putstr_fd_printf(char *s, int fd)
{
	int	a;

	a = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		a = 6;
		return (a);
	}
	if (fd < 0)
		fd = -fd;
	while (s[a])
	{
		write(fd, &s[a], 1);
		a++;
	}
	return (a);
}
