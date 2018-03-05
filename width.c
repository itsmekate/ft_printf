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

int ft_width(const char *str)
{
	int w;

	w = ft_atoi(str);
	return (w);
}

int ft_print(t_flag *fl, char *res, int count, int minus)
{
	int j;

    if ((fl->precision == 0 && ft_strcmp(res, "0") == 0))
        j = fl->minwidth;
	else
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
            (fl->plus != 0 && !minus) ? j-- : 0;
			ft_putzero(j);
		}
		else if (fl->precision < fl->minwidth)
		{
			minus == 1 ? j-- : 0 ;
			ft_putspace(j);
            minus == 1 ? ft_putchr('-') : 0;
		}
        if (fl->precision > ft_strlen(res))
        {
            fl->minwidth = fl->precision  - ft_strlen(res);
            ft_putzero(fl->precision - ft_strlen(res));
            ft_putstr(res);
            free(res);
            return (fl->precision);
        }
        else if (fl->precision == 0 && ft_strcmp(res, "0") == 0)
        {
            free(res);
            return (fl->minwidth);
        }
        ft_putstr(res);
		free(res);
		return (fl->minwidth);
	}
	else
	{
        if (fl->precision > ft_strlen(res))
        {
            count += fl->precision;
            ft_putzero(fl->precision - ft_strlen(res));
            ft_putstr(res);
            free(res);
            return (count);
        }
        else if (fl->precision == 0 && ft_strcmp(res, "0") == 0)
        {
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
}

int ft_print_min(t_flag *fl, char *res, int count, int minus)
{
	int j = 0;

    if ( (fl->precision == 0 && ft_strcmp(res, "0") == 0))
    {
        j = fl->minwidth;
    }
    else
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