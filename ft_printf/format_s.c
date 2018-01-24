/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:16 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:16 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				unicode_to_utf8(wchar_t c, unsigned char *b)
{
	if (c < (1 << 7))
		*b++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*b++ = (unsigned char)((c >> 6) | 0xC0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*b++ = (unsigned char)(((c >> 12)) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*b++ = (unsigned char)(((c >> 18)) | 0xF0);
		*b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	*b = '\0';
}

int					ft_form_big_c(va_list *arg, t_flg *f)
{
	wchar_t			c;
	int				ret;
	char			k;
	unsigned char	buff[5];

	k = (f->z) ? '0' : ' ';
	c = va_arg(*arg, wchar_t);
	ret = (!c) ? 1 : 0;
	unicode_to_utf8(c, buff);
	if (f->w)
	{
		ret = slen((char*)buff);
		if (f->min)
		{
			ft_puts(f->fd, (char*)buff);
			if (ret < f->w)
				ret += fill_with(f->fd, ' ', f->w - ret);
			return (ret);
		}
		if (ret < f->w)
			ret = fill_with(f->fd, k, f->w - ret);
	}
	return (ret + ft_puts(f->fd, (char*)buff));
}

int					ft_form_c(va_list *arg, t_flg *f)
{
	char			c;
	int				ret;
	char			k;

	if (f->len == l)
		return (ft_form_big_c(arg, f));
	k = (f->z) ? '0' : ' ';
	c = (char)va_arg(*arg, int);
	ret = 0;
	if (f->w)
	{
		ret = 1;
		if (f->min)
		{
			ft_printch(f->fd, c);
			if (ret < f->w)
				ret += fill_with(f->fd, ' ', f->w - ret);
			return (ret);
		}
		if (ret < f->w)
			ret = fill_with(f->fd, k, f->w - ret);
	}
	return (ret + ft_printch(f->fd, c));
}

int					ft_form_big_s(va_list *arg, t_flg *f)
{
	wchar_t			*str;
	char			k;
	char			*new;

	k = (f->z) ? '0' : ' ';
	str = va_arg(*arg, wchar_t*);
	new = (!str) ? ft_dup("(null)") : str_utf8(str, f->prec);
	if (f->w)
	{
		if (f->min)
		{
			if (slen(new) < f->w)
				new = ft_join(new, ft_add(k, f->w - slen(new)));
			return (ft_puts(f->fd, new));
		}
		if (slen(new) < f->w)
			new = ft_join(ft_add(k, f->w - slen(new)), new);
	}
	return (ft_puts(f->fd, new));
}

int					ft_form_s(va_list *arg, t_flg *f)
{
	char			*str;
	char			k;

	if (f->len == l)
		return (ft_form_big_s(arg, f));
	k = (f->z && !f->min) ? '0' : ' ';
	str = va_arg(*arg, char*);
	str = (!str) ? ft_dup("(null)") : str;
	if (f->prec > -1 && f->prec < slen(str))
		str = ft_strim(str, f->prec);
	if (f->w)
	{
		if (f->min)
		{
			if (slen(str) < f->w)
				str = ft_join(str, ft_add(k, f->w - slen(str)));
			return (ft_puts(f->fd, str));
		}
		if (slen(str) < f->w)
			str = ft_join(ft_add(k, f->w - slen(str)), str);
	}
	return (ft_puts(f->fd, str));
}
