/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:16:43 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 17:04:28 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_null_flag(t_flag *fl)
{
	fl->h = 0;
	fl->l = 0;
	fl->i = 0;
	fl->z = 0;
	fl->j = 0;
	fl->minus = 0;
	fl->plus = 0;
	fl->zero = 0;
	fl->hash = 0;
	fl->space = 0;
	fl->minwidth = 0;
	fl->precision = -1;
}

int			ft_write_precision(const char *tmp, t_flag *fl)
{
	fl->precision = ft_atoi(tmp);
	return (ft_num_len(fl->precision));
}

const char	*ft_write_flags_more_more(t_flag *fl, const char *tmp)
{
	if (*tmp == '.')
	{
		tmp++;
		if (ft_strcmp(tmp, "-1") != 0)
			tmp += ft_write_precision(tmp, fl);
	}
	return (tmp);
}

void		ft_write_more(t_flag *fl, const char *tmp)
{
	tmp = ft_write_flags_more_more(fl, tmp);
	while (*tmp == 'h' || *tmp == 'l' || *tmp == 'j' || *tmp == 'z')
	{
		if (*tmp == 'h')
		{
			tmp++;
			if (*tmp == 'h')
				fl->h = 2;
			else
				fl->h = 1;
		}
		if (*tmp == 'l')
		{
			tmp++;
			if (*tmp == 'l')
				fl->l = 2;
			else
				fl->l = 1;
		}
		if (*tmp == 'j')
			fl->j = 1;
		if (*tmp == 'z')
			fl->z = 1;
		tmp++;
	}
}

t_flag		ft_write_flags(const char *str)
{
	const char	*tmp;
	t_flag		fl;

	tmp = str;
	ft_null_flag(&fl);
	while (*tmp == '+' || *tmp == '-' ||
			*tmp == ' ' || *tmp == '0' || *tmp == '#')
	{
		(*tmp == '#') ? fl.hash = 1 : 0;
		(*tmp == '+') ? fl.plus = 1 : 0;
		(*tmp == '-') ? fl.minus = 1 : 0;
		(*tmp == ' ') ? fl.space = 1 : 0;
		(*tmp == '0') ? fl.zero = 1 : 0;
		tmp++;
	}
	if (*tmp >= '0' && *tmp <= '9')
	{
		fl.minwidth = ft_width(tmp);
		tmp += ft_num_len(fl.minwidth);
	}
	ft_write_more(&fl, tmp);
	return (fl);
}
