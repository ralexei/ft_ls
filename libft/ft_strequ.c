/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:27:50 by pgore             #+#    #+#             */
/*   Updated: 2016/10/17 18:27:50 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (1);
	if (s1 && s2)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		while (*s1 && *s2)
		{
			if (*s1 == *s2)
			{
				s1++;
				s2++;
			}
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
