/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:33:56 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/17 12:33:58 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (c > 255)
		c = c % 256;
	while (s[i])
	{
		if (s[i] == c)
			return (s = &s[i]);
		i++;
	}
	if (c == 0)
		return (s = &s[i]);
	return (0);
}
