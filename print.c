/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:58:41 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 19:58:46 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_width(t_flag *fl, char *res, int minus, int j)
{
	if (fl->zero == 1 && fl->minus != 1)
	{
		(fl->plus == 1 && !minus && !fl->minus) ? j -= write(1, "+", 1) : 0;
		(minus == 1) ? j -= write(1, "-", 1) : 0;
		ft_putzero(j);
	}
	else
	{
		((minus == 1) || (fl->plus == 1 && !minus && !fl->minus)) ? j-- : 0;
		ft_putspace(j);
		(minus == 1) ? write(1, "-", 1) : 0;
		(fl->plus == 1 && !minus && !fl->minus) ? write(1, "+", 1) : 0;
	}
}

int			print_width_prec(t_flag *fl, char *res)
{
	if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") != 0)
	{
		ft_putzero(fl->precision - ft_strlen(res));
		ft_putstr(res);
		free(res);
		return (fl->minwidth);
	}
	if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") == 0)
	{
		ft_putzero(fl->precision);
		free(res);
		return (fl->minwidth);
	}
	(fl->precision <= 0 && ft_strcmp(res, "0") == 0) ? 0 : ft_putstr(res);
	free(res);
	return (fl->minwidth);
}

int			print_no_w(t_flag *fl, char *res, int count, int minus)
{
	(minus == 1) ? write(1, "-", 1) : 0;
	(fl->plus == 1 && !minus && !fl->minus) ? write(1, "+", 1) : 0;
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

int			ft_print(t_flag *fl, char *res, int count, int minus)
{
	int j;

	if (ft_strcmp(res, "0") == 0 && fl->precision <= 0)
		j = fl->minwidth - fl->space;
	else if (fl->precision > ft_strlen(res))
		j = fl->minwidth - fl->precision - fl->space;
	else
		j = fl->minwidth - ft_strlen(res) - fl->space;
	if (fl->zero && fl->minwidth - fl->precision && fl->precision > 0)
		fl->zero = 0;
	if (fl->minwidth != 0 && j > 0)
	{
		print_width(fl, res, minus, j);
		return (print_width_prec(fl, res));
	}
	else
		return (print_no_w(fl, res, count, minus));
}
