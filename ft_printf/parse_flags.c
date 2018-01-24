/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:18 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:18 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			parse_precision(t_flg *f, char **s)
{
	if (!ft_findch(FORMAT, f->fmt) && f->prec > -1 && f->z && f->w)
		f->prec = -1;
	if (f->h && ft_low(f->fmt) == 'o' && f->prec > slen(*s))
		f->h = 0;
	if (f->prec > slen(*s) && **s != '-')
		*s = ft_join(ft_add('0', f->prec - slen(*s)), *s);
	else if (f->prec >= slen(*s) && **s == '-')
	{
		**s = '0';
		*s = ft_join(ft_add('0', f->prec - slen(*s) + 1), *s);
		*s[f->prec - slen(*s) + 1] = '-';
	}
	f->i = (ft_low(f->fmt) == 'd' && f->plus && f->z && **s != '-') ? 1 : f->i;
	f->i = (ft_low(f->fmt) == 'd' && slen(*s) == 1 && **s == '0') ? 1 : f->i;
	if (f->z && f->w > slen(*s) && !f->min && f->prec < 0 && **s == '-')
	{
		**s = '0';
		*s = ft_join(ft_add('0', f->w - slen(*s)), *s);
		*s[f->w - slen(*s)] = '-';
	}
}

void			parse_flags(t_flg *f, char **s)
{
	f->fmt = (f->fmt == 'i' || f->fmt == 'D') ? 'd' : f->fmt;
	f->i = ((f->plus && f->fmt == 'd') || (f->h && f->z)) ? 1 : 0;
	f->i = (f->fmt == 'p' || (ft_low(f->fmt) == 'x' && f->h && f->z)) ? 2 : 0;
	parse_precision(f, s);
	if (f->z && f->w > slen(*s) && !f->min && f->prec < 0 && **s && **s != '-')
		*s = ft_join(ft_add('0', f->w - slen(*s) - f->i), *s);
	else if (f->z && f->w > slen(*s) && !**s && !f->min && f->prec < 0)
		*s = ft_join(ft_add('0', f->w - slen(*s)), *s);
	if (f->plus && f->fmt == 'd' && **s != '-')
		*s = ft_join("+", *s);
	if ((f->h && f->fmt != 'd' && ft_low(f->fmt) != 'u') || f->fmt == 'p')
	{
		*s = (ft_low(f->fmt) == 'x' && **s != '0' && !**s) ? ft_dup("0") : *s;
		if ((f->fmt != 'X') || f->fmt == 'p')
			*s = (ft_low(f->fmt) == 'o') ? ft_join("0", *s) : ft_join("0x", *s);
		else if (f->fmt == 'X')
			*s = ft_join("0X", *s);
	}
	if (f->w > slen(*s) && !f->min)
		*s = ft_join(ft_add(' ', f->w - slen(*s)), *s);
	if (f->fmt == 'd' && f->space && **s != '-' && !f->plus && **s != ' ')
		*s = ft_join(" ", *s);
	if (f->min && f->w > slen(*s))
		*s = ft_join(*s, ft_add(' ', f->w - slen(*s)));
}

int				ft_form_u(va_list *arg, t_flg *f)
{
	char		*str;
	uintmax_t	nr;

	if (f->fmt == 'U')
		f->len = l;
	nr = ft_parse_uint(arg, f);
	if (f->prec == 0 && nr == 0)
		str = ft_newstr(0);
	else
		str = itoa_base(nr, 10, f->fmt);
	parse_flags(f, &str);
	return (ft_puts(f->fd, str));
}

int				wslen(wchar_t *s)
{
	wchar_t		*p;
	int			i;

	i = 0;
	p = s;
	while (p[i])
		i++;
	return (i);
}

char			*ft_concat(char *s1, char *s2)
{
	int			i;
	int			j;

	i = slen(s1);
	j = 0;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
