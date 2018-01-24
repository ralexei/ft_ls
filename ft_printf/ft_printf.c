/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:18 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:18 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			formats_chars(char f)
{
	if (ft_findch(FORMAT, f))
		return (1);
	return (0);
}

int			init_flags(int fd, t_flg *flags)
{
	flags->space = 0;
	flags->h = 0;
	flags->z = 0;
	flags->plus = 0;
	flags->min = 0;
	flags->prec = -1;
	flags->w = 0;
	flags->len = none;
	flags->fmt = 0;
	flags->i = 0;
	flags->fd = fd;
	return (-1);
}

int			format_specifier(va_list *arg, t_flg *f)
{
	if (f->fmt == '%')
		return (ft_percent(f));
	if (ft_low(f->fmt) == 'd' || f->fmt == 'i')
		return (ft_form_i_d(arg, f));
	if (f->fmt == 's')
		return (ft_form_s(arg, f));
	if (f->fmt == 'S')
		return (ft_form_big_s(arg, f));
	if (f->fmt == 'c')
		return (ft_form_c(arg, f));
	if (f->fmt == 'C')
		return (ft_form_big_c(arg, f));
	if (ft_low(f->fmt) == 'x')
		return (ft_form_hex(arg, f));
	if (ft_low(f->fmt) == 'o')
		return (ft_form_oct(arg, f));
	if (f->fmt == 'p')
		return (ft_form_p(arg, f));
	if (f->fmt == 'b')
		return (ft_form_b(arg, f));
	if (ft_low(f->fmt) == 'u')
		return (ft_form_u(arg, f));
	return (0);
}

int			process_all(int fd, char **str, va_list *arg)
{
	t_flg	flg;
	int		i;
	char	*rez;

	i = init_flags(fd, &flg);
	rez = ft_dup(++(*str));
	while (rez[++i] && !formats_chars(rez[i]))
		if (!ft_findch(SPECS, rez[i]))
			break ;
	rez = ft_strim(rez, i + 1);
	while (**str && !formats_chars(**str))
	{
		process_flags(str, arg, &flg);
		if (!ft_findch(SPECS, **str))
			break ;
		*str += 1;
	}
	flg.fmt = **str;
	rez = ft_add(flg.fmt, 1);
	if (!ft_findch(FORMAT, flg.fmt))
	{
		parse_flags(&flg, &rez);
		return (ft_puts(flg.fd, rez));
	}
	return (format_specifier(arg, &flg));
}

int			ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg;
	char	*str;

	ret = 0;
	va_start(arg, format);
	str = ft_dup((char*)format);
	while (*str)
	{
		if (*str == '%')
			ret += process_all(1, &str, &arg);
		else
			ret += ft_printch(1, *str);
		str++;
	}
	va_end(arg);
	return (ret);
}
