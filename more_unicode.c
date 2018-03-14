/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:33:11 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 20:33:13 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size(wchar_t i)
{
	int count;

	if (i <= 0x7F)
		count = 1;
	else if (i <= 0x7FF)
		count = 2;
	else if (i <= 0xFFFF)
		count = 3;
	else
		count = 4;
	return (count);
}

int	ft_unicodesize(wchar_t *i)
{
	int count;
	int j;

	count = 0;
	j = 0;
	while (i[j])
	{
		if (i[j] <= 0x7F)
			count++;
		else if (i[j] <= 0x7FF)
			count += 2;
		else if (i[j] <= 0xFFFF)
			count += 3;
		else
			count += 4;
		j++;
	}
	return (count);
}

int	ft_check_prec(wchar_t *i, int j, int count, t_flag *fl)
{
	while (i[j] && count < fl->precision)
	{
		count += size(i[j]);
		if (count > fl->precision)
			break ;
		j++;
	}
	j == 0 ? 0 : j--;
	(count > fl->precision) ? count -= size(i[j]) : 0;
	if (fl->precision > count && fl->minwidth)
		ft_putspace(fl->precision - count);
	while (*i && j > -1)
	{
		print_unicode(*i);
		i++;
		j--;
	}
	return (count);
}

int	ft_printbigs_min(wchar_t *i, t_flag *fl)
{
	int	count;
	int j;

	j = 0;
	count = 0;
	if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1 && (count++))
		write(1, " ", 1);
	j = fl->minwidth - ft_unicodesize(i);
	if (fl->minwidth != 0 && j > 0)
	{
		ft_putuni(i, count, fl);
		fl->zero == 1 ? ft_putzero(j) : ft_putspace(j);
		return (fl->minwidth);
	}
	else
		return (ft_putuni(i, count, fl));
}

int	ft_putuni(wchar_t *i, int count, t_flag *fl)
{
	int j;

	j = 0;
	if (fl->precision > 0)
	{
		return (ft_check_prec(i, j, count, fl));
	}
	while (*i)
	{
		count += print_unicode(*i);
		i++;
	}
	return (count);
}
