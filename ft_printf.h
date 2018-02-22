/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:40 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/15 17:02:04 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_type
{
	int			h;
	int			l;
	int			i;
	int			z;
	int			j;
	int			minus;
	int			plus;
	int			zero;
	int			hash;
	int 		space;
	int			minwidth;
	int			precision;
}				t_flag;

void			ft_null_flag(t_flag *fl);
int				ft_strlen(char *str);
t_flag			ft_write_flags(const char *str);
int				ft_width(const char *str);
void			ft_putchr(int c);
void			ft_putnbr(ssize_t n);
int				ft_putstr(char *str);
void            ft_putzero(int j);
void            ft_putspace(int j);
char            *ft_strchr(const char *s, int c);
char			*ft_itoa_base_s(uintmax_t value, int base);
char			*ft_itoa_base_S(uintmax_t value, int base);
int				print_unicode(unsigned int i);
int				ft_is_s(char *str, t_flag *fl);
int				ft_is_c(intmax_t c, t_flag *fl);
int				ft_is_d(intmax_t i, t_flag *fl);
int				ft_is_o(intmax_t i, t_flag *fl);
int				ft_is_o_big(intmax_t i, t_flag *fl);
int				ft_is_d_big(intmax_t i, t_flag *fl);
int				ft_is_x(intmax_t i, t_flag *fl);
int				ft_is_x_big(intmax_t i, t_flag *fl);
int				ft_is_u(intmax_t i, t_flag *fl);
int				ft_is_u_big(intmax_t i, t_flag *fl);
int				ft_is_p(intmax_t i, t_flag *fl);
int				ft_is_c_big(unsigned int i, t_flag *fl);
int				ft_is_s_big(wchar_t *i, t_flag *fl);
int				ft_is_per(int count, t_flag *fl);
int				ft_putuni(wchar_t *i, int count);
int				ft_printbigs(wchar_t *i, t_flag *fl);
int				ft_printbigs_min(wchar_t *i, t_flag *fl);
int				ft_print(t_flag *fl, char *res, int count, int minus);
int				ft_print_min(t_flag *fl, char *res, int count, int minus);
int				ft_print_hex(t_flag *fl, char *res, int count);
int 			ft_print_hexmin(t_flag *fl, char *res, int count);
int				ft_print_point(t_flag *fl, char *res, int count);
int				ft_print_octal(t_flag *fl, char *res, int count);
int				ft_print_octalmin(t_flag *fl, char *res, int count);
int             ft_other_chars(char c, int count, t_flag fl);
int				ft_printf(const char *str, ...);

#endif
