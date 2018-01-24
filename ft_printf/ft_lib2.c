/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:17 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:17 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_revstr(char *str)
{
	char	*new;
	int		i;
	int		last;

	i = 0;
	last = slen(str) - 1;
	new = ft_newstr(last + 1);
	while (last > -1)
		new[i++] = str[last--];
	new[i] = '\0';
	return (new);
}

int			ft_getnr(char *str, t_flg *f)
{
	int		i;
	int		rez;
	int		neg;

	i = 0;
	rez = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if ((str[i] == '-' || str[i] == '+') && is_number(str[i + 1]))
	{
		if (str[i] == '-')
		{
			neg = -1;
			f->min = 1;
		}
		i++;
	}
	while (is_number(str[i]))
	{
		rez *= 10;
		rez += str[i++] - '0';
	}
	return (rez * neg);
}

char		*ft_findch(char *s, int c)
{
	char	*kek;

	kek = s;
	while (*kek != c)
		if (!(*kek++))
			return (NULL);
	return (kek);
}

int			fill_with(int fd, char what, int much)
{
	int		i;

	i = 0;
	while (i++ < much)
		ft_printch(fd, what);
	return (much);
}

int			ft_islowc(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
