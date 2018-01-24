/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:15 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:15 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char				*str_utf8(wchar_t *wstr, int prec)
{
	char			*str;
	int				len;
	unsigned char	buff[5];

	if (prec < 0)
		prec = wslen(wstr) * sizeof(wstr);
	str = ft_newstr(sizeof(char) * prec + 1);
	while (*wstr)
	{
		unicode_to_utf8(*wstr, buff);
		len = slen((char*)buff);
		if (prec - len > -1)
		{
			ft_concat(str, (char*)buff);
			prec -= len;
		}
		else
			break ;
		wstr++;
	}
	return (str);
}
