/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:42:04 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:42:06 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list				*cpy_elem(t_list *elem)
{
	t_list			*tmp;

	tmp = new_elem(elem->info.path, elem->info.name, elem->info.st);
	return (tmp);
}

char				*form_path(char *path, char *name, char *rez)
{
	ft_strcpy(rez, path);
	ft_strcat(rez, "/");
	ft_strcat(rez, name);
	return (rez);
}

t_list				*new_elem(char *path, char *name, t_stat st)
{
	t_list			*tmp_node;

	tmp_node = (t_list *)ft_memalloc(sizeof(t_list));
	if (!tmp_node)
		return (NULL);
	tmp_node->info.st = st;
	ft_strcpy(tmp_node->info.name, name);
	ft_strcpy(tmp_node->info.path, path);
	tmp_node->next = NULL;
	return (tmp_node);
}
