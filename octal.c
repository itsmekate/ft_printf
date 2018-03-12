/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:02:44 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 19:04:28 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_octal_width(t_flag *fl, char *res, int j)
{
	(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
	(fl->hash == 1 && fl->precision != 0) ? write(1, "0", 1) : 0;
	if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") != 0)
	{
		fl->minwidth += fl->precision - ft_strlen(res) - 1;
		ft_putzero(fl->precision - ft_strlen(res));
		ft_putstr(res);
		free(res);
		return (fl->minwidth - 1);
	}
	if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") == 0)
	{
		free(res);
		return (fl->minwidth);
	}
	(fl->precision <= 0 && ft_strcmp(res, "0") == 0) ? 0 : ft_putstr(res);
	free(res);
	return (fl->minwidth);
}

int	octal_nw(t_flag *fl, char *res, int count)
{
	if ((fl->hash == 1 && fl->precision == -1)
		|| (fl->hash && fl->precision == 0))
		count += write(1, "0", 1);
	if (fl->precision == 0 && ft_strcmp(res, "0") == 0)
	{
		free(res);
		return (count);
	}
	if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") != 0)
	{
		count += fl->precision - ft_strlen(res);
		ft_putzero(fl->precision - ft_strlen(res));
		count += ft_putstr(res);
		free(res);
		return (count);
	}
	if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") == 0)
	{
		free(res);
		return (fl->minwidth);
	}
	else
		count += ft_putstr(res);
	free(res);
	return (count);
}

int	ft_print_octal(t_flag *fl, char *res, int count)
{
	int j;

	if ((fl->precision == 0 && ft_strcmp(res, "0") == 0))
		j = fl->minwidth;
	else if (fl->precision > ft_strlen(res))
		j = fl->minwidth - fl->precision;
	else
		j = fl->minwidth - ft_strlen(res);
	(fl->hash == 1 && fl->precision != 0) ? j-- : 0;
	if (fl->minwidth != 0 && j > 0)
		return (ft_octal_width(fl, res, j));
	else
		return (octal_nw(fl, res, count));
}

int	check(t_flag *fl, char *res, int j)
{
	if (fl->precision > ft_strlen(res))
	{
		fl->minwidth += fl->precision - ft_strlen(res) - 1;
		ft_putzero(fl->precision - ft_strlen(res));
		ft_putstr(res);
		j = fl->minwidth - ft_strlen(res) - 1;
		if (fl->minus != 1 || (fl->minwidth - fl->precision) > 0)
			(fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
	}
	else
	{
		ft_putstr(res);
		(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
	}
	free(res);
	return (fl->minwidth);
}

int	ft_print_octalmin(t_flag *fl, char *res, int count)
{
	int j;

	if (fl->precision > ft_strlen(res))
		j = fl->minwidth;
	else
		j = fl->minwidth - ft_strlen(res);
	if (fl->hash == 1 && (j--))
		write(1, "0", 1);
	if (fl->minwidth != 0 && j > 0)
		return (check(fl, res, j));
	else
	{
		count += ft_putstr(res);
		free(res);
		return (count);
	}
}
