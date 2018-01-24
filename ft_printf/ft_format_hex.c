/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:16 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:16 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			itoa_rec(uintmax_t nb, int base, char *str, int (*f)(int))
{
	if (nb < (UNSG)base)
	{
		*str = f(BASE[nb % base]);
		str[1] = '\0';
	}
	else
	{
		*str = f(BASE[nb % base]);
		itoa_rec(nb / base, base, str + 1, f);
	}
}

char			*itoa_base(uintmax_t value, int base, char c)
{
	char	*str;

	if (base < 2 || base > 16 || !(str = ft_newstr(100)))
		return (NULL);
	itoa_rec(value, base, str, (ft_islowc(c)) ? ft_low : ft_upcase);
	return (ft_revstr(str));
}

int				ft_form_hex(va_list *arg, t_flg *f)
{
	uintmax_t	nb;
	char		*str;

	nb = ft_parse_uint(arg, f);
	if (nb == 0 && f->prec == 0)
	{
		str = ft_dup("");
		f->h = 0;
	}
	else if (nb == 0 && f->h && f->prec < 0)
		return (ft_puts(f->fd, "0"));
	else
		str = itoa_base(nb, 16, f->fmt);
	parse_flags(f, &str);
	return (ft_puts(f->fd, str));
}

int				ft_form_oct(va_list *arg, t_flg *f)
{
	uintmax_t	nb;
	char		*str;

	if (f->fmt == 'O')
		f->len = l;
	nb = ft_parse_uint(arg, f);
	if (nb == 0 && f->prec == 0 && !f->h)
		str = ft_dup("");
	else if (nb == 0 && f->prec <= 0 && f->h)
	{
		str = ft_dup("0");
		f->h = 0;
	}
	else
		str = itoa_base(nb, 8, f->fmt);
	parse_flags(f, &str);
	return (ft_puts(f->fd, str));
}

int				ft_form_p(va_list *arg, t_flg *f)
{
	uintmax_t	p;
	char		*str;

	p = (uintmax_t)va_arg(*arg, uintmax_t);
	str = (f->prec == 0) ? ft_dup("") : itoa_base(p, 16, 'c');
	parse_flags(f, &str);
	return (ft_puts(f->fd, str));
}
