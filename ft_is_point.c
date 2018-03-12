/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:09:20 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 18:11:08 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointmin(t_flag *fl, char *res, int count)
{
	int j;

	j = fl->minwidth - ft_strlen(res) - 2;
	if (fl->minwidth != 0 && j > 0)
	{
		write(1, "0x", 2);
		ft_putstr(res);
		(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
		free(res);
		return (fl->minwidth);
	}
	else
	{
		write(1, "0x", 2);
		count += 2;
		count += ft_putstr(res);
		free(res);
		return (count);
	}
}

int	ft_print_point_width(t_flag *fl, char *res, int j)
{
	if (fl->zero == 1 && fl->minus != 1)
	{
		write(1, "0x", 2);
		ft_putzero(j);
	}
	else
	{
		ft_putspace(j);
		write(1, "0x", 2);
	}
	if (fl->precision == 0 && ft_strcmp(res, "0") == 0 && fl->minwidth <= 0)
	{
		free(res);
		return (fl->minwidth);
	}
	if (fl->precision > ft_strlen(res))
	{
		fl->minwidth += fl->precision - ft_strlen(res);
		ft_putzero(fl->precision - ft_strlen(res));
	}
	ft_putstr(res);
	free(res);
	return (fl->minwidth);
}

int	print_point_nw(t_flag *fl, char *res, int count)
{
	count += write(1, "0x", 2);
	if (fl->precision == 0 && ft_strcmp(res, "0") == 0 && fl->minwidth <= 0)
	{
		free(res);
		return (count);
	}
	if (fl->precision > ft_strlen(res))
	{
		count += fl->precision - ft_strlen(res);
		ft_putzero(fl->precision - ft_strlen(res));
	}
	count += ft_putstr(res);
	free(res);
	return (count);
}

int	ft_print_point(t_flag *fl, char *res, int count)
{
	int j;

	j = fl->minwidth - ft_strlen(res) - 2;
	if (fl->minwidth != 0 && j > 0)
		return (ft_print_point_width(fl, res, j));
	else
		return (print_point_nw(fl, res, count));
}

int	ft_is_p(intmax_t i, t_flag *fl)
{
	int		count;
	char	*res;

	count = 0;
	res = ft_itoa_base_s(i, 16);
	if (fl->minus != 1)
		count += ft_print_point(fl, res, count);
	else
		count += ft_print_pointmin(fl, res, count);
	return (count);
}
