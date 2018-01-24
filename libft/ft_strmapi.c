/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:27:52 by pgore             #+#    #+#             */
/*   Updated: 2016/10/17 18:27:52 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		length;
	int		i;

	i = 0;
	if (s && f)
	{
		str = NULL;
		length = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (length + 1));
		if (str)
		{
			while (i < length)
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
