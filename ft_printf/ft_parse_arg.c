/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:20:18 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:20:18 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

intmax_t	ft_parse_int(va_list *arg, t_flg *f)
{
	intmax_t nbr;

	if (f->len == l)
		return (va_arg(*arg, long int));
	if (f->len == ll)
		return (va_arg(*arg, long long int));
	if (f->len == z)
		return (va_arg(*arg, size_t));
	if (f->len == j)
		return (va_arg(*arg, intmax_t));
	nbr = va_arg(*arg, int);
	if (f->len == h)
		return ((short int)nbr);
	else if (f->len == hh)
		return ((char)nbr);
	return (nbr);
}

uintmax_t	ft_parse_uint(va_list *arg, t_flg *f)
{
	uintmax_t nbr;

	if (f->len == l)
		return (va_arg(*arg, long unsigned int));
	if (f->len == ll)
		return (va_arg(*arg, long long unsigned int));
	if (f->len == z)
		return (va_arg(*arg, size_t));
	if (f->len == j)
		return (va_arg(*arg, uintmax_t));
	nbr = va_arg(*arg, unsigned int);
	if (f->len == h)
		return ((unsigned short int)nbr);
	else if (f->len == hh)
		return ((unsigned char)nbr);
	return (nbr);
}
