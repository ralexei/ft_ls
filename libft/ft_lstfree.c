/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:27:42 by pgore             #+#    #+#             */
/*   Updated: 2016/10/17 18:27:42 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstfree(t_list **alst)
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		free(*alst);
		*alst = tmp;
	}
}
