/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:17 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:17 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_newstr(size_t size)
{
	char	*rez;

	if (!(rez = (char*)malloc(size + 1)))
		return (NULL);
	ft_makezero(rez, size + 1);
	return (rez);
}

char		*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (slen(s1) + slen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_add(char c, int nr)
{
	char	*ret;
	int		i;

	i = 0;
	nr = ABS(nr);
	ret = ft_newstr(nr + 1);
	while (i < nr)
		ret[i++] = c;
	return (ret);
}

int			ft_percent(t_flg *f)
{
	char	*str;

	str = ft_dup("%");
	f->h = 0;
	if (f->prec > -1)
		f->prec = -1;
	parse_flags(f, &str);
	return (ft_puts(f->fd, str));
}

int			ft_printf_fd(int fd, const char *format, ...)
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
			ret += process_all(fd, &str, &arg);
		else
			ret += ft_printch(fd, *str);
		str++;
	}
	va_end(arg);
	return (ret);
}
