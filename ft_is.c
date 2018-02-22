/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:07 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/03 18:37:09 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_is_s(char *str, t_flag *fl)
{
	int j;

    if (str == NULL)
    {
        write(1, "(null)" , 6);
        return (6);
    }
//	if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1)
//		write(1, " ", 1);
	j = fl->minwidth - ft_strlen(str);
	if (fl->minwidth != 0 && j > 0)
	{
        (fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
		ft_putstr(str);
		return (fl->minwidth);
	}
	else
		return (ft_putstr(str));
}

int ft_is_c(intmax_t c, t_flag *fl)
{
	int j;

    if (fl->l == 1)
        c = (wint_t)c;
//	if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1 &&  c != '0')
//		write(1, " ", 1);
	if (fl->minwidth != 0 && fl->minus != 1)
	{
		j = fl->minwidth - 1;
        (fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
		ft_putchr(c);
		return (fl->minwidth);
	}
	else if (fl->minwidth != 0 && fl->minus == 1)
	{
		j = fl->minwidth - 1;
		ft_putchr(c);
        (fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
		return (fl->minwidth);
	}
	else
	{
		ft_putchr(c);
		return (1);
	}
}



int ft_is_per(int count, t_flag *fl)
{
	int j = 0;

	j = fl->minwidth - 1;
	if (fl->minus != 1)
	{
		if (fl->minwidth != 0 && j > 0)
		{
            (fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
			ft_putchr('%');
			return (fl->minwidth);
		}
		else
		{
			ft_putchr('%');
			return (1);
		}
	}
	else
	{
		if (fl->minwidth != 0 && j > 0)
		{
			ft_putchr('%');
            (fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
			return (fl->minwidth);
		}
		else
		{
			ft_putchr('%');
			return (1);
		}
	}
}