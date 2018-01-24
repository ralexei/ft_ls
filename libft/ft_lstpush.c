/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:26:21 by pgore             #+#    #+#             */
/*   Updated: 2017/02/16 08:03:34 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstpush(t_list **begin_lst, t_list *new)
{
	if (*begin_lst == NULL)
		*begin_lst = new;
	else
		ft_lstpush(&((*begin_lst)->next), new);
}
