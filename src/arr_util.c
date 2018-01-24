/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:41:46 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:41:48 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				counter(off_t nr)
{
	int			i;

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

void			init_st(t_ls *k)
{
	k->flg = 0;
	k->flg2 = 0;
	k->opt.a = 0;
	k->opt.recur = 0;
	k->opt.f = 0;
	k->opt.l = 0;
	k->opt.rev = 0;
	k->opt.t = 0;
	k->opt.g = 0;
	k->opt.d = 0;
	k->opt.u = 0;
	k->opt.one = 0;
	k->folder_num = 0;
	k->cnt_siz = 0;
	init_sizes(k);
}

void			ft_put_flags(t_ls *k, char flag)
{
	if (flag == 'a')
		k->opt.a = 1;
	else if (flag == 'R')
		k->opt.recur = 1;
	else if (flag == 'r')
		k->opt.rev = 1;
	else if (flag == 'f')
		k->opt.f = 1;
	else if (flag == 't')
		k->opt.t = 1;
	else if (flag == '1')
		k->opt.one = 1;
	else if (flag == 'g')
		k->opt.g = 1;
	else if (flag == 'd')
		k->opt.d = 1;
	else if (flag == 'u')
		k->opt.u = 1;
	else if (flag == 'l')
		k->opt.l = 1;
}

int				check_flg(t_ls *k, char *av)
{
	int			i;
	int			is;
	int			menos;

	i = 0;
	is = 0;
	menos = 0;
	while (av[i])
	{
		if (av[i] == '-' && av[i + 1])
			menos = 1;
		if (menos)
		{
			if (!ft_strchr(FLAGS, av[i]) && av[i] != '-')
				ft_usage_error(av[i]);
			else
			{
				is++;
				ft_put_flags(k, av[i]);
			}
		}
		i++;
	}
	return (is);
}

void			put_av(char **av, int ac, t_ls *k, t_list **lst)
{
	int			i;
	int			maps_found;
	t_stat		st;

	i = 1;
	maps_found = 0;
	while (i < ac)
	{
		if (!check_flg(k, av[i]))
		{
			if (lstat(av[i], &st) < 0)
			{
				k->folder_num = 1;
				ft_no_file(av[i]);
			}
			maps_found = 1;
			popu(av[i], lst, k);
		}
		i++;
	}
	if (!maps_found)
		popu(".", lst, k);
	do_ls(k, lst);
	ft_lstfree_ls(lst);
}
