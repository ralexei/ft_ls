/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:41:56 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:41:57 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		go_link(t_list *lst)
{
	char	buf[100];
	char	tmp_path[1024];

	ft_bzero(buf, 100);
	ft_bzero(tmp_path, 1024);
	if (S_ISLNK(lst->info.st.st_mode))
	{
		if (ft_strcmp(lst->info.path, "\0"))
			form_path(lst->info.path, lst->info.name, tmp_path);
		else
			ft_strcpy(tmp_path, lst->info.name);
		readlink(tmp_path, buf, 100);
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

void		calc_size(t_list *lst)
{
	t_list	*tmp;
	char	path[1024];
	int		cnt_siz;

	tmp = lst;
	cnt_siz = 0;
	ft_strcpy(path, lst->info.path);
	while (tmp && !ft_strcmp(tmp->info.path, path))
	{
		if (tmp->info.name[0])
			cnt_siz += tmp->info.st.st_blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	print_nr_pad(cnt_siz, 0, 0);
	ft_putchar('\n');
}

void		ft_usage_error(char c)
{
	ft_putstr_fd("/bin/ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\
		\n", 2);
	exit(1);
}

void		ft_no_file(char *file)
{
	ft_putstr_fd("ls: ", 2);
	if (file[0] != '\0')
		ft_putstr_fd(file, 2);
	else
		ft_putstr_fd("fts_open", 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}
