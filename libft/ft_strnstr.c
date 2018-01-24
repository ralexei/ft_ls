/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:27:53 by pgore             #+#    #+#             */
/*   Updated: 2016/10/17 18:27:53 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	n;

	if (*s2 == '\0')
		return ((char*)s1);
	n = ft_strlen(s2);
	while (*s1 != '\0' && len-- >= n)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, n) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
