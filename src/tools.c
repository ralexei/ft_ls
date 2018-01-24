/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:43:00 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:43:01 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			nr_len(int nr)
{
	int		i;

	if (nr == 0)
		return (1);
	i = 0;
	while (nr)
	{
		nr /= 10;
		i++;
	}
	return (i);
}

void		print_pad(char *str, int cnt, int left)
{
	int		len;
	int		spaces;

	len = (int)ft_strlen(str);
	spaces = cnt - len;
	if (spaces < 0)
		spaces = 0;
	if (left)
		ft_putstr(str);
	while (spaces)
	{
		ft_putchar(' ');
		spaces--;
	}
	if (!left)
		ft_putstr(str);
}

void		print_nr_pad(int nr, int cnt, int left)
{
	int		len;
	int		spaces;

	len = nr_len(nr);
	spaces = cnt - len;
	if (spaces < 0)
		spaces = 0;
	if (left)
		ft_putnbr(nr);
	while (spaces)
	{
		ft_putchar(' ');
		spaces--;
	}
	if (!left)
		ft_putnbr(nr);
}

void		ft_lstfree_ls(t_list **alst)
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		ft_memdel((void **)alst);
		*alst = tmp;
	}
}
