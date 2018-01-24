/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:27:39 by pgore             #+#    #+#             */
/*   Updated: 2017/01/29 16:58:09 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int				if_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
			|| c == '\v')
		return (1);
	return (0);
}

static int		check_for_maxint(const char *str)
{
	int			i;
	char		rez[10];

	i = 0;
	while (!if_space(str[i]) && str[i] && i < 10)
	{
		rez[i] = str[i];
		i++;
	}
	if (i < 10)
		return (0);
	if (ft_strcmp(rez, "2147483647") == 0 && i == 10)
		return (2147483647);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			neg;
	int			rez;

	i = 0;
	neg = 1;
	rez = 0;
	while (if_space(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] >= '0' &&
		str[i + 1] <= '9')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez *= 10;
		rez += str[i] - '0';
		i++;
	}
	return (neg * rez);
}
