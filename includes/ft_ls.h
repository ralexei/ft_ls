/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:00:21 by alrusu            #+#    #+#             */
/*   Updated: 2017/04/04 18:00:23 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>
# include <sys/stat.h>
# include <string.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <sys/syslimits.h>
# include <sys/ioctl.h>

# define FLAGS "laRrtugfd1"
# define KNRM "\x1B[0m"
# define KRED "\x1B[31m"
# define KGRN "\033[1m\033[32m"
# define KYEL "\033[1m\033[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\033[1m\033[36m"
# define KWHT "\x1B[37m"
# define BGYEL "\33[43m"
# define BGCYN "\33[46m"
# define HUE "\33[7m"
# define MTSPEC(x) (x->info.st.st_mtimespec)

typedef struct stat		t_stat;
typedef struct dirent	t_drn;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;
typedef struct timespec	t_spec;

typedef struct	s_opt
{
	int			a : 2;
	int			recur : 2;
	int			f : 2;
	int			l : 2;
	int			rev : 2;
	int			t : 2;
	int			g : 2;
	int			d : 2;
	int			u : 2;
	int			one : 2;
}				t_opt;

typedef struct	s_ls
{
	int			folder_num;
	int			bsiz;
	int			flg : 2;
	int			flg2 : 2;
	int			lnks;
	int			pwsiz;
	int			grsiz;
	int			minsiz;
	int			majsiz;
	int			devflg : 2;
	int			cnt_siz;
	t_opt		opt;
}				t_ls;

void			file_mode(mode_t mode);
void			sort_by_order(t_list *lst, t_ls k);
void			permissions(mode_t mode);
void			put_time(time_t tim);
void			init_sizes(t_ls *k);
void			prepare_indentation(t_ls *k, t_list *lst);
int				counter(off_t nr);
void			color_n(int mode);
void			size_put(struct stat st, t_ls *k);
void			init_st(t_ls *k);
int				check_flg(t_ls *k, char *av);
void			put_av(char **av, int ac, t_ls *k, t_list **f);
char			*form_path(char *path, char *name, char *rez);
t_list			*new_elem(char *path, char *name, t_stat st);
void			read_folder(char *path, t_list **lst, t_ls *k);
void			popu(char *path, t_list **lst, t_ls *k);
void			swap(t_list *node_a, t_list *node_b, int *flag);
int				ft_strcmp_lowers(const char *s1, const char *s2);
void			sort_this_fucking_list(t_list *lst, t_ls k);
void			sort_by_path(t_list *lst, t_ls k);
void			recursive(char *path, t_list **lst, t_ls *k);
void			print_long(t_ls *k, t_list *lst);
void			sort_da_sheet(t_list *lst, t_ls k);
void			do_ls(t_ls *k, t_list **lst);
void			ft_usage_error(char c);
void			ft_no_file(char *file);
void			print_long_mid(t_ls *k, t_list *tmp);
void			calc_size(t_list *lst);
void			go_link(t_list *lst);
void			sort_wout_point(t_list *lst, t_ls k);
void			print_pad(char *str, int cnt, int left);
void			print_nr_pad(int nr, int cnt, int left);
void			ft_lstfree_ls(t_list **alst);
void			ft_lstfree_ls(t_list **alst);
void			print_nr_pad(int nr, int cnt, int left);
char			*form_path(char *path, char *name, char *rez);
t_list			*cpy_elem(t_list *elem);

#endif
