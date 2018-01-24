/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:27:44 by pgore             #+#    #+#             */
/*   Updated: 2016/10/17 18:27:44 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char*)s;
	while (str[i] != d && i < (n - 1))
		i++;
	if (str[i] == d && n != 0)
		return (str += i);
	return (NULL);
}
