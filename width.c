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

int		ft_atoi(const char *str)
{
	int				minus;
	unsigned long	num;

	num = 0;
	minus = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		num *= 10;
		num += *str - 48;
		str++;
		if (num > 9223372036854775807 && minus == -1)
			return (0);
		if (num > 9223372036854775807 && minus == 1)
			return (-1);
	}
	return (num * minus);
}

int ft_width(const char *str)
{
	int w;

	w = ft_atoi(str);
	return (w);
}

int ft_print(t_flag *fl, char *res, int count, int minus)
{
	int j;

	j = fl->minwidth - ft_strlen(res);
	if (fl->minwidth != 0 && j > 0)
	{
		if (fl->zero == 1 && fl->minus != 1)
		{
            if (fl->space == 1)
                    j -= write(1, " ", 1);
			if (minus == 1)
			{
				j--;
				ft_putchr('-');
			}
			if (fl->plus == 1 && !minus)
				j--;
			ft_putzero(j);
		}
		else
		{
			minus == 1 ? j-- : 0 ;
			ft_putspace(j);
            minus == 1 ? ft_putchr('-') : 0;
		}
		ft_putstr(res);
		free(res);
		return (fl->minwidth);
	}
	else
	{
        minus == 1 ? ft_putchr('-') : 0;
		count += ft_putstr(res);
		free(res);
		return (count);
	}
}

int ft_print_min(t_flag *fl, char *res, int count, int minus)
{
	int j = 0;

	j = fl->minwidth - ft_strlen(res);
	if (minus == 1)
	{
		j--;
		ft_putchr('-');
	}
	if (fl->minwidth != 0 && j > 0)
	{
		ft_putstr(res);
        (fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
		free(res);
		return (fl->minwidth);
	}
	else
	{
		count += ft_putstr(res);
		free(res);
		return (count);
	}
}