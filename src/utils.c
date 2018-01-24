/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:43:15 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:43:17 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				size_put(t_stat st, t_ls *k)
{
	int				i;
	int				flg;

	i = 0;
	flg = 0;
	if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
	{
		print_nr_pad(major(st.st_rdev), k->majsiz + 1, 0);
		ft_putchar(',');
		print_nr_pad(minor(st.st_rdev), k->minsiz + 1, 0);
		ft_putchar(' ');
	}
	else
	{
		flg = (k->minsiz || k->majsiz) ? (k->majsiz + k->minsiz + 3) : k->bsiz;
		print_nr_pad((int)(st.st_size), flg, 0);
		ft_putchar(' ');
	}
}

void				color_n(int mode)
{
	if (S_ISDIR(mode))
		ft_putstr(KCYN);
	else if (mode & S_IEXEC)
		ft_putstr(KGRN);
	else
		ft_putstr(KNRM);
}

void				init_sizes(t_ls *k)
{
	k->bsiz = 0;
	k->lnks = 0;
	k->pwsiz = 0;
	k->grsiz = 0;
	k->devflg = 0;
	k->minsiz = 0;
	k->majsiz = 0;
}

static void			fuck_norme(t_ls *k, t_list *tmp, int *cnt)
{
	k->devflg = 1;
	if ((*cnt = counter(minor(tmp->info.st.st_rdev))) > k->minsiz)
		k->minsiz = *cnt;
	if ((*cnt = counter(major(tmp->info.st.st_rdev))) > k->majsiz)
		k->majsiz = *cnt;
	if (k->bsiz > k->minsiz)
		k->minsiz = k->bsiz;
}

void				prepare_indentation(t_ls *k, t_list *lst)
{
	t_list			*tmp;
	t_pwd			*pwd;
	t_grp			*grp;
	int				cnt;

	tmp = lst;
	while (tmp)
	{
		pwd = getpwuid(tmp->info.st.st_uid);
		grp = getgrgid(tmp->info.st.st_gid);
		if ((cnt = counter(tmp->info.st.st_size)) > k->bsiz)
			k->bsiz = cnt;
		if ((cnt = counter(tmp->info.st.st_nlink)) > k->lnks)
			k->lnks = cnt;
		if ((cnt = (int)ft_strlen(pwd->pw_name)) > k->pwsiz)
			k->pwsiz = cnt;
		if ((cnt = (int)ft_strlen(grp->gr_name)) > k->grsiz)
			k->grsiz = cnt;
		if (S_ISCHR(tmp->info.st.st_mode))
			fuck_norme(k, tmp, &cnt);
		tmp = tmp->next;
	}
}
