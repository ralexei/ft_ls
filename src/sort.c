/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:42:51 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:42:53 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				swap(t_list *node_a, t_list *node_b, int *flag)
{
	t_info			tmp_info;

	tmp_info = node_a->info;
	node_a->info = node_b->info;
	node_b->info = tmp_info;
	*flag = 1;
}

int					compare_t(t_spec t1, t_spec t2, char *s1, char *s2)
{
	if (t1.tv_sec > t2.tv_sec || (t1.tv_sec == t2.tv_sec && t1.tv_nsec > \
		t2.tv_nsec) || (t1.tv_sec == t2.tv_sec && t1.tv_nsec == t2.tv_nsec && \
		(ft_strcmp(s1, s2) < 0)))
		return (0);
	return (1);
}

void				sort_this_fucking_list(t_list *lst, t_ls k)
{
	int				swapped;
	int				comp;
	t_list			*ptr1;

	comp = 0;
	swapped = 1;
	if (lst == NULL || (lst && !(lst->next)))
		return ;
	while (swapped)
	{
		swapped = 0;
		ptr1 = lst;
		while (ptr1->next != NULL)
		{
			if (k.opt.rev)
				comp = ft_strcmp(ptr1->next->info.name, ptr1->info.name);
			else
				comp = ft_strcmp(ptr1->info.name, ptr1->next->info.name);
			if (comp > 0 && !ft_strcmp(ptr1->info.path, ptr1->next->info.path))
				swap(ptr1, ptr1->next, &swapped);
			ptr1 = ptr1->next;
		}
	}
}

void				sort_by_time(t_list *lst, t_ls k)
{
	int				swapped;
	int				comp;
	t_list			*ptr1;

	comp = 0;
	swapped = 1;
	if (lst == NULL || (lst && !(lst->next)))
		return ;
	while (swapped)
	{
		swapped = 0;
		ptr1 = lst;
		while (ptr1->next != NULL)
		{
			comp = (k.opt.rev) ? compare_t(MTSPEC(ptr1->next), MTSPEC(ptr1), \
			ptr1->next->info.name, ptr1->info.name) : compare_t(MTSPEC(ptr1), \
			MTSPEC(ptr1->next), ptr1->info.name, ptr1->next->info.name);
			if (comp > 0 && !ft_strcmp(ptr1->info.path, ptr1->next->info.path))
				swap(ptr1, ptr1->next, &swapped);
			ptr1 = ptr1->next;
		}
	}
}

void				sort_da_sheet(t_list *lst, t_ls k)
{
	if (k.opt.t)
		sort_by_time(lst, k);
	else
		sort_this_fucking_list(lst, k);
}
