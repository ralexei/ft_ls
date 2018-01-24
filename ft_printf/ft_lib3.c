/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:17 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:17 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				*ft_cpy(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char				*ft_dup(char *s)
{
	size_t			len;
	void			*new;

	len = slen(s) + 1;
	new = ft_newstr(len);
	if (new == NULL)
		return (NULL);
	return ((char*)ft_cpy(new, (const char*)s, len));
}

char				*ft_strim(char *str, int nr)
{
	char			*new;
	int				i;

	i = 0;
	new = ft_newstr(nr);
	while (i < nr && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void				*ft_sets(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char*)s;
	while (i < n)
		str[i++] = c;
	return (str);
}

void				ft_makezero(void *s, size_t n)
{
	if (n > 0)
		ft_sets(s, 0, n);
}
