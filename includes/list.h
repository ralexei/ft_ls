/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:00:34 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 18:00:35 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <sys/stat.h>
# include <sys/syslimits.h>

typedef struct		s_info
{
	char			name[NAME_MAX];
	char			path[PATH_MAX];
	struct stat		st;
}					t_info;

typedef struct		s_list
{
	t_info			info;
	struct s_list	*elements;
	struct s_list	*next;
}					t_list;
#endif
