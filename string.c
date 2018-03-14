/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:57:42 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 18:03:28 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str_no_prec(int tmp, char *str, t_flag *fl, int j)
{
	int count;

	count = 0;
	tmp = fl->precision;
	if (tmp != 0 && fl->precision != -1)
	{
		if (fl->precision < ft_strlen(str))
		{
			j = fl->minwidth - fl->precision;
			j > 0 ? count += j : 0;
			while (j > 0)
				j -= write(1, " ", 1);
		}
		while (tmp-- && *str)
		{
			count += write(1, &(*str), 1);
			str++;
		}
	}
	else
		count += ft_putstr(str);
	return (count);
}

int	print_str_null(char *str, t_flag *fl, int j, int len)
{
	int tmp;

	j = fl->minwidth - len;
	(fl->zero == 1  && !fl->minus) ? ft_putzero(j) : ft_putspace(j);
	tmp = fl->precision;
	if (tmp != 0 && tmp != -1)
	{
		j = len - tmp;
		while (j > 0)
			j -= write(1, " ", 1);
		while (tmp-- && *str)
			str += write(1, &(*str), 1);
	}
	return (fl->minwidth);
}

int	check_str(char *str, t_flag *fl, int j, int len)
{
	int tmp;

	(fl->zero == 1  && !fl->minus) ? ft_putzero(j) : ft_putspace(j);
	tmp = fl->precision;
	if (tmp != 0 && tmp != -1 && ft_strcmp(str, "") != 0)
	{
		j = len - tmp;
		while (j > 0)
			j -= write(1, " ", 1);
		while (tmp-- && *str)
			str += write(1, &(*str), 1);
	}
	else if (fl->precision == 0)
	{
		return (fl->minwidth);
	}
	else
		ft_putstr(str);
	return (fl->minwidth);
}

int	check_str2(char *str, t_flag *fl, int j, int len)
{
	int tmp;

	tmp = fl->precision;
	if (tmp != 0 && tmp != -1 && ft_strcmp(str, "") != 0)
	{
		while (tmp-- && *str)
			str += write(1, &(*str), 1);
		j = fl->minwidth - fl->precision;
		(fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
	}
	else
	{
		ft_putstr(str);
		j = fl->minwidth - len;
		(fl->zero == 1  && !fl->minus) ? ft_putzero(j) : ft_putspace(j);
	}
	return (fl->minwidth);
}

int	ft_is_s(char *str, t_flag *fl)
{
	int j;
	int len;

	len = 0;
	if ((str == NULL && fl->plus) ||
		(str == NULL && fl->space) ||
		(str == NULL && fl->precision == -1))
		return (str_zero(fl));
	else if (str == NULL)
		return (print_str_null(str, fl, j, len));
	else
		len = ft_strlen(str);
	if ((fl->precision > len && fl->minwidth) || fl->precision)
		j = fl->minwidth - len;
	else if (fl->precision < len)
		j = fl->minwidth - fl->precision;
	else
		j = fl->minwidth - len;
	if (fl->minwidth != 0 && j > 0 && (!fl->minus))
		return (check_str(str, fl, j, len));
	else if (fl->minwidth != 0 && fl->minus)
		return (check_str2(str, fl, j, len));
	else
		return (print_str_no_prec(0, str, fl, j));
}
