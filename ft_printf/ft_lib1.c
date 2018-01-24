/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:16 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:16 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printch(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int		ft_puts(int fd, char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_printch(fd, s[i++]);
	return (i);
}

int		slen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_low(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int		ft_upcase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
