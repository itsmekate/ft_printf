/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexidecimal_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:14:30 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 20:20:14 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_hex_width(t_flag *fl, int j, int big)
{
	if (fl->zero == 1 && fl->minus != 1)
	{
		(fl->hash == 1 && big && fl->precision != 0) ? write(1, "0X", 2) : 0;
		(fl->hash == 1 && !big && fl->precision != 0) ? write(1, "0x", 2) : 0;
		ft_putzero(j);
	}
	else
	{
		ft_putspace(j);
		(fl->hash == 1 && big && fl->precision != 0) ? write(1, "0X", 2) : 0;
		(fl->hash == 1 && !big && fl->precision != 0) ? write(1, "0x", 2) : 0;
	}
}

int			print_hex_width_ret(t_flag *fl, char *res, int big)
{
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
	(fl->hash == 1 && big && fl->precision > 0) ? write(1, "0X", 2) : 0;
	(fl->hash == 1 && !big && fl->precision > 0) ? write(1, "0x", 2) : 0;
	(fl->precision <= 0 && ft_strcmp(res, "0") == 0) ? 0 : ft_putstr(res);
	free(res);
	return (fl->minwidth);
}

int			print_hex_no_width(t_flag *fl, char *res, int count, int big)
{
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

int			ft_print_hex(t_flag *fl, char *res, int count, int big)
{
	int j;

	if ((fl->precision == 0 && ft_strcmp(res, "0") == 0))
		j = fl->minwidth;
	else if (fl->precision > ft_strlen(res))
		j = fl->minwidth - fl->precision;
	else
		j = fl->minwidth - ft_strlen(res);
	(fl->hash == 1 && fl->precision != 0) ? j -= 2 : 0;
	if (fl->minwidth != 0 && j > 0)
	{
		print_hex_width(fl, j, big);
		return (print_hex_width_ret(fl, res, big));
	}
	else
	{
		if (fl->hash == 1 && big && ft_strcmp(res, "0") != 0)
			count += write(1, "0X", 2);
		else if (fl->hash == 1 && !big && ft_strcmp(res, "0") != 0)
			count += write(1, "0x", 2);
		return (print_hex_no_width(fl, res, count, big));
	}
}
