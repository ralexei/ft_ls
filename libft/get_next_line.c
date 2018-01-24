/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:51:38 by pgore             #+#    #+#             */
/*   Updated: 2017/01/28 12:51:28 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lst		*find_fd(int fd, t_lst *lst)
{
	t_lst			*tmp;

	tmp = lst;
	if (lst)
	{
		while (tmp->next)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
		if (tmp->fd == fd)
			return (tmp);
		if (!(tmp->next = (t_lst*)malloc(sizeof(t_lst))))
			return (NULL);
		tmp = tmp->next;
	}
	else if (!(tmp = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	tmp->fd = fd;
	tmp->buff = ft_strnew(BUFF_SIZE + 1);
	tmp->next = NULL;
	tmp->begin = (lst) ? lst : tmp;
	return (tmp);
}

static void			change_buff(char buff[], int pos, char **line)
{
	int				i;

	i = 0;
	if (buff[i] == '\0' && *line != '\0')
		return ;
	while (buff[i + pos + 1] != '\0')
	{
		buff[i] = buff[i + pos + 1];
		i++;
	}
	while (i < BUFF_SIZE)
		buff[i++] = '\0';
}

static char			*ret_line(char buff[], char *old, int pos)
{
	int				i;
	int				j;
	char			*new;

	i = -1;
	j = 0;
	new = ft_strnew(ft_strlen(old) + pos + 1);
	while (old[++i])
		new[i] = old[i];
	while (j < pos)
		new[i++] = buff[j++];
	free(old);
	return (new);
}

static int			find_newline(char buff[])
{
	int				pos;

	pos = 0;
	while (buff[pos] && buff[pos] != '\n')
		pos++;
	return (pos);
}

int					get_next_line(int const fd, char **line)
{
	static t_lst	*lst = NULL;
	int				ret;
	int				pos;

	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	*line = ft_strnew(1);
	lst = find_fd(fd, lst);
	while (ret > 0)
	{
		if (lst->buff[0] == '\0')
			if ((ret = read(fd, lst->buff, BUFF_SIZE)) < 0)
				return (-1);
		pos = find_newline(lst->buff);
		*line = ret_line(lst->buff, *line, pos);
		if (lst->buff[pos] || (!(lst->buff[0]) && *line[0]))
		{
			change_buff(lst->buff, pos, line);
			lst = lst->begin;
			return (1);
		}
		ft_strclr(lst->buff);
	}
	return (0);
}
