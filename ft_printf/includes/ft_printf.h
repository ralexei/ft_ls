/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:28:49 by pgore             #+#    #+#             */
/*   Updated: 2017/01/04 13:28:50 by pgore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>
# include <inttypes.h>
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define UNSG unsigned
# define UNSHINT UNSG short int
# define LG long int
# define LLG long LG
# define FORMAT "sSpdDioOuUxXcCb%"
# define SPECS " #*.-+lhjz;:1234567890sSpdDioOuUxXcCb%"
# define BASE "0123456789abcdef"

typedef struct		s_flg
{
	int				space : 2;
	int				h : 2;
	int				z : 2;
	int				plus : 2;
	int				min : 2;
	int				w;
	int				prec;
	char			fmt;
	int				i;
	int				fd;
	enum
	{
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				len;
}					t_flg;

int					ft_printch(int fd, char c);
int					ft_puts(int fd, char *str);
int					slen(char *str);
int					ft_low(int c);
int					ft_upcase(int c);
int					ft_islowc(int c);
int					ft_nrlen(int nb);
char				*ft_revstr(char *str);
char				*itoa_base(uintmax_t nb, int base, char c);
void				itoa_rec(uintmax_t nb, int base, char *str,
						int (*f)(int));
void				itoa_rec_dec(intmax_t nb, char *str);
char				*ft_itoa_dec(intmax_t value);
void				unicode_to_utf8(wchar_t c, unsigned char *b);
int					ft_getnr(char *str, t_flg *flg);
int					is_number(char c);
char				*ft_findch(char *s, int c);
int					fill_with(int fd, char c, int nr);
char				*ft_dup(char *s);
void				*ft_cpy(void *dst, const void *src, size_t n);
void				*ft_sets(void *s, int c, size_t n);
void				ft_makezero(void *s, size_t n);
char				*ft_newstr(size_t size);
char				*ft_strim(char *str, int nr);
char				*ft_join(char *s1, char *s2);
char				*ft_add(char c, int nr);
int					wslen(wchar_t *s);
char				*str_utf8(wchar_t *wstr, int prec);
char				*ft_concat(char *s1, char *s2);
/*
***********************************************************************
*/
int					ft_printf(const char *str, ...);
int					ft_printf_fd(int fd, const char *format, ...);
int					format_specifier(va_list *arg, t_flg *flg);
int					process_all(int fd, char **str, va_list *arg);
int					init_flags(int fd, t_flg *flags);
void				process_flag1(char **c, va_list *arg, t_flg *flg);
void				process_flags(char **c, va_list *arg, t_flg *flg);
void				process_len(char **c, t_flg *flg);
void				parse_precision(t_flg *f, char **s);
void				parse_flags(t_flg *f, char **str);
uintmax_t			ft_parse_uint(va_list *arg, t_flg *f);
intmax_t			ft_parse_int(va_list *arg, t_flg *f);
int					ft_form_c(va_list *arg, t_flg *flg);
int					ft_form_big_c(va_list *arg, t_flg *flg);
int					ft_form_s(va_list *arg, t_flg *flg);
int					ft_form_big_s(va_list *arg, t_flg *flg);
int					ft_form_i_d(va_list *arg, t_flg *f);
int					ft_form_hex(va_list *arg, t_flg *flg);
int					ft_form_oct(va_list *arg, t_flg *flg);
int					ft_form_p(va_list *arg, t_flg *flg);
int					ft_form_b(va_list *arg, t_flg *flg);
int					ft_form_u(va_list *arg, t_flg *f);
int					ft_percent(t_flg *f);
#endif
