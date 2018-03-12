/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:07 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/03 18:37:09 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	unsigned long	num;

	num = 0;
	if (*str < '0' && *str > '9')
		return (-2);
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		num *= 10;
		num += *str - 48;
		str++;
		if (num > 922337203685477580)
			return (-1);
	}
	return (num);
}

int	ft_width(const char *str)
{
	int w;

	w = ft_atoi(str);
	return (w);
}

int	print_min_width(t_flag *fl, char *res, int j, int count)
{
	if (fl->precision > ft_strlen(res))
	{
		count = fl->precision - ft_strlen(res);
		ft_putzero(fl->precision - ft_strlen(res));
	}
	count += ft_putstr(res) + j;
	(fl->plus) ? j-- : 0;
	(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
	free(res);
	return (count);
}

int	print_min_nw(t_flag *fl, char *res, int j, int count)
{
	if (fl->precision > ft_strlen(res))
	{
		count += fl->precision - ft_strlen(res);
		ft_putzero(fl->precision - ft_strlen(res));
	}
	count += ft_putstr(res);
	free(res);
	return (count);
}

int	ft_print_min(t_flag *fl, char *res, int count, int minus)
{
	int j;

	if ((fl->precision == 0 && ft_strcmp(res, "0") == 0))
		j = fl->minwidth;
	else if (fl->precision > ft_strlen(res))
		j = fl->minwidth - fl->precision + fl->plus;
	else
		j = fl->minwidth - ft_strlen(res);
	(fl->plus == 1 && !minus) ? j -= write(1, "+", 1) : 0;
	(minus == 1) ? j -= write(1, "-", 1) : 0;
	if (fl->minwidth != 0 && j > 0)
		return (print_min_width(fl, res, j, count));
	else
		return (print_min_nw(fl, res, j, count));
}
