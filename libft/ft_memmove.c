/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:27:45 by pgore             #+#    #+#             */
/*   Updated: 2016/10/17 18:27:45 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*dest;
	size_t			i;

	i = 0;
	str = (unsigned char*)src;
	dest = (unsigned char*)dst;
	if (str < dest)
	{
		while (++i <= len)
			dest[len - i] = str[len - i];
	}
	else
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	return (dst);
}
