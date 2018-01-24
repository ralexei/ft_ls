/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:45:17 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 17:46:09 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				put_time(time_t tim)
{
	char			**c;
	time_t			new;
	int				i;

	i = -1;
	new = time(NULL);
	c = ft_strsplit(ctime(&tim), ' ');
	c[4][4] = '\0';
	c[3][5] = '\0';
	print_pad(c[1], 0, 0);
	ft_putchar(' ');
	print_pad(c[2], 2, 0);
	ft_putchar(' ');
	if ((new - tim) < 15780000)
		ft_putstr(c[3]);
	else
	{
		ft_putchar(' ');
		ft_putstr(c[4]);
	}
	ft_putchar(' ');
	while (c[++i])
		ft_strdel(&c[i]);
}

char				print_exec_mod(int ex, int flag)
{
	if (ex && (flag == S_ISUID || flag == S_ISGID))
		return ('s');
	else if (!ex && (flag == S_ISUID || flag == S_ISGID))
		return ('S');
	else if (ex && flag == S_ISVTX)
		return ('t');
	else if (!ex && flag == S_ISVTX)
		return ('T');
	else if (ex)
		return ('x');
	return ('-');
}

void				permissions(mode_t mode)
{
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	ft_putchar(print_exec_mod(mode & S_IXUSR, mode & S_ISUID));
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	ft_putchar(print_exec_mod(mode & S_IXGRP, mode & S_ISGID));
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	ft_putchar(print_exec_mod(mode & S_IXOTH, mode & S_ISVTX));
	ft_putstr("  ");
}

void				file_mode(mode_t mode)
{
	if (S_ISREG(mode))
		ft_putchar('-');
	else if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
	else
		ft_putchar('?');
	permissions(mode);
}

int					main(int ac, char **av)
{
	t_ls			k;
	t_list			*folder_list;

	init_st(&k);
	folder_list = NULL;
	put_av(av, ac, &k, &folder_list);
	return (1);
}
