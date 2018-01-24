/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:42:41 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:42:42 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				read_folder(char *path, t_list **lst, t_ls *k)
{
	t_list			*tmp_node;
	DIR				*dr;
	t_drn			*drn;
	char			tmp_path[PATH_MAX];
	t_stat			st;

	if (!(dr = opendir(path)))
		return ;
	tmp_node = NULL;
	while ((drn = readdir(dr)))
	{
		if (drn->d_name[0] == '.' && !k->opt.a)
			continue ;
		form_path(path, drn->d_name, tmp_path);
		lstat(tmp_path, &st);
		ft_lstpush(&tmp_node, new_elem(path, drn->d_name, st));
	}
	sort_da_sheet(tmp_node, *k);
	ft_lstadd(&tmp_node, new_elem(path, "\0", st));
	ft_lstpush(lst, tmp_node);
}

void				popu(char *path, t_list **lst, t_ls *k)
{
	t_stat			st;

	if (lstat(path, &st) >= 0)
	{
		if (S_ISDIR(st.st_mode))
		{
			if (k->opt.recur > 0)
				recursive(path, lst, k);
			else
				read_folder(path, lst, k);
		}
		else
			ft_lstadd(lst, new_elem("\0", path, st));
	}
}

t_list				*read_dir(char *path, t_ls k)
{
	DIR				*dir;
	t_drn			*drn;
	t_list			*tmp_node;
	char			tmp[PATH_MAX];
	t_stat			st;

	tmp_node = NULL;
	if (!(dir = opendir(path)))
		return (NULL);
	while ((drn = readdir(dir)))
	{
		form_path(path, drn->d_name, tmp);
		lstat(tmp, &st);
		if (S_ISDIR(st.st_mode))
			ft_lstpush(&tmp_node, new_elem(path, drn->d_name, st));
	}
	if (tmp_node)
		sort_da_sheet(tmp_node, k);
	closedir(dir);
	return (tmp_node);
}

void				process_dirs(char *start_path, t_ls k, t_list **list)
{
	t_list			*dirs;
	char			path[PATH_MAX];

	dirs = NULL;
	if (!(dirs = read_dir(start_path, k)))
		return ;
	while (dirs)
	{
		if (ft_strcmp(dirs->info.name, ".") && ft_strcmp(dirs->info.name, "..")\
			&& ((!k.opt.a && dirs->info.name[0] != '.') || k.opt.a))
		{
			form_path(start_path, dirs->info.name, path);
			ft_strcpy(dirs->info.path, path);
			ft_lstpush(list, cpy_elem(dirs));
			process_dirs(path, k, list);
		}
		dirs = dirs->next;
	}
	ft_lstfree_ls(&dirs);
}

void				recursive(char *path, t_list **lst, t_ls *k)
{
	t_list			*tmp;

	tmp = NULL;
	process_dirs(path, *k, &tmp);
	read_folder(path, lst, k);
	while (tmp)
	{
		read_folder(tmp->info.path, lst, k);
		tmp = tmp->next;
	}
}
