/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_ing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:42:15 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:42:16 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_long_mid(t_ls *k, t_list *tmp)
{
	t_pwd			*pwd;
	t_grp			*grp;

	pwd = getpwuid(tmp->info.st.st_uid);
	grp = getgrgid(tmp->info.st.st_gid);
	file_mode(tmp->info.st.st_mode);
	print_nr_pad(tmp->info.st.st_nlink, k->lnks, 0);
	ft_putchar(' ');
	print_pad(pwd->pw_name, k->pwsiz, 1);
	ft_putstr("  ");
	print_pad(grp->gr_name, k->grsiz, 1);
	ft_putstr("  ");
	size_put(tmp->info.st, k);
	put_time(tmp->info.st.st_mtime);
	ft_putstr(tmp->info.name);
	go_link(tmp);
	ft_putchar('\n');
}

void				print_long(t_ls *k, t_list *lst)
{
	t_list			*tmp;
	char			*pathin;

	tmp = lst;
	pathin = tmp->info.path;
	if (ft_strcmp(tmp->info.path, "\0"))
		calc_size(tmp);
	while (tmp)
	{
		if (ft_strcmp(pathin, tmp->info.path))
		{
			pathin = tmp->info.path;
			init_sizes(k);
			prepare_indentation(k, lst);
			ft_putchar('\n');
			ft_putstr(pathin);
			ft_putstr(":\n");
			calc_size(tmp);
		}
		if (ft_strcmp(tmp->info.name, "\0"))
			print_long_mid(k, tmp);
		tmp = tmp->next;
	}
}

void				print_other(t_list *lst, t_ls *k)
{
	t_list			*tmp;
	char			*pathin;

	tmp = lst;
	pathin = tmp->info.path;
	if (k->folder_num && ft_strcmp(pathin, "\0"))
	{
		ft_putstr(pathin);
		ft_putstr(":\n");
	}
	while (tmp)
	{
		if (ft_strcmp(pathin, tmp->info.path))
		{
			pathin = tmp->info.path;
			ft_putchar('\n');
			ft_putstr(pathin);
			ft_putstr(":\n");
		}
		if (ft_strcmp(tmp->info.name, "\0"))
			ft_putendl(tmp->info.name);
		tmp = tmp->next;
	}
}

void				do_ls(t_ls *k, t_list **lst)
{
	if (*lst)
	{
		prepare_indentation(k, *lst);
		if (k->opt.l)
			print_long(k, *lst);
		else
			print_other(*lst, k);
	}
}
