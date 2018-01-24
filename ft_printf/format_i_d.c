/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_i_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:15 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:15 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				ft_nrlen(int nb)
{
	int		ret;

	if (!nb)
		return (1);
	ret = 0;
	if (nb < 0)
	{
		nb *= -1;
		ret++;
	}
	while (nb)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

void			itoa_rec_dec(intmax_t nb, char *str)
{
	if (nb < 10)
	{
		*str = BASE[nb % 10];
		str[1] = '\0';
	}
	else
	{
		*str = BASE[nb % 10];
		itoa_rec_dec(nb / 10, str + 1);
	}
}

char			*ft_itoa_dec(intmax_t value)
{
	char	*str;

	str = ft_newstr(100);
	itoa_rec_dec(ABS(value), str);
	if (value < 0)
	{
		str[slen(str)] = '-';
		str[slen(str) + 1] = '\0';
	}
	return (ft_revstr(str));
}

int				ft_form_i_d(va_list *arg, t_flg *f)
{
	intmax_t	nb;
	char		*str;

	if (f->fmt == 'D' && f->len < l)
		f->len = l;
	nb = ft_parse_int(arg, f);
	if (nb < -9223372036854775807 && f->len >= l)
		str = ft_dup("-9223372036854775808");
	else if (nb == 0 && f->prec == 0)
		str = ft_dup("");
	else
		str = ft_itoa_dec(nb);
	parse_flags(f, &str);
	return (ft_puts(f->fd, str));
}

int				ft_form_b(va_list *arg, t_flg *flg)
{
	uintmax_t	nr;
	char		*str;

	nr = ft_parse_uint(arg, flg);
	str = ft_newstr(100);
	itoa_rec(nr, 2, str, ft_low);
	if (slen(str) == 1)
	{
		str[1] = '0';
		str[2] = '\0';
	}
	str = ft_revstr(str);
	parse_flags(flg, &str);
	return (ft_puts(flg->fd, str));
}
