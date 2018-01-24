/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:19 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:19 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void		process_flag1(char **c, va_list *arg, t_flg *flg)
{
	if (**c == ' ')
		flg->space = 1;
	else if (**c == '#')
		flg->h = 1;
	else if (**c == '0')
		flg->z = 1;
	else if (**c == '+')
		flg->plus = 1;
	else if (**c == '-')
		flg->min = 1;
	else if (**c == '.' && *(*c + 1) != '*')
	{
		flg->prec = (is_number(*(*c + 1))) ? ft_getnr(*c + 1, flg) : 0;
		*c += (is_number(*(*c + 1))) ? ft_nrlen(flg->prec) : 0;
	}
	else if (**c == '.' && *(*c + 1) == '*')
	{
		flg->prec = va_arg(*arg, int);
		(*c)++;
	}
	else if (**c >= '1' && **c <= '9')
	{
		flg->w = ft_getnr(*c, flg);
		*c += ft_nrlen(flg->w) - 1;
	}
}

void		process_len(char **c, t_flg *flg)
{
	if (**c == 'h' && flg->len < l && flg->len != h)
		flg->len = h;
	else if (flg->len == h && **c == 'h')
		flg->len = hh;
	else if (**c == 'l' && flg->len < l)
		flg->len = l;
	else if (flg->len == l && **c == 'l')
		flg->len = ll;
	else if (**c == 'j')
		flg->len = j;
	else if (**c == 'z')
		flg->len = z;
}

void		process_flags(char **c, va_list *arg, t_flg *flg)
{
	if (**c == '*')
	{
		flg->w = va_arg(*arg, int);
		if (flg->w < 0)
			flg->min = 1;
		flg->w = ABS(flg->w);
	}
	process_flag1(c, arg, flg);
	process_len(c, flg);
}
