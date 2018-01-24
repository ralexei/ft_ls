/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:27:43 by pgore             #+#    #+#             */
/*   Updated: 2016/10/17 18:27:43 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (mem && size)
	{
		ft_bzero(mem, size);
		return ((void *)mem);
	}
	return ((void *)0);
}
