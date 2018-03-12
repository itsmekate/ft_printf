/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:07 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 18:09:13 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_c(intmax_t c, t_flag *fl)
{
	int j;

	if (fl->l == 1)
		c = (wint_t)c;
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

int	ft_is_per(t_flag *fl)
{
	int j;

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
			return ((int)write(1, "%", 1));
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
			return ((int)write(1, "%", 1));
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	str_zero(t_flag *fl)
{
	if (fl->precision != 0 && fl->precision != -1)
	{
		write(1, "(null)", (size_t)fl->precision);
		return (fl->precision);
	}
	else
		write(1, "(null)", 6);
	return (6);
}
