/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:33:01 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 20:33:03 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_c_big(unsigned int i, t_flag *fl)
{
	int	count;

	count = print_unicode(i);
	return (count);
}

int	ft_is_s_big(wchar_t *i, t_flag *fl)
{
	if (i == NULL)
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
	if (fl->minus != 1)
		return (ft_printbigs(i, fl));
	else
		return (ft_printbigs_min(i, fl));
}

int	ft_printbigs(wchar_t *i, t_flag *fl)
{
	int	count;
	int j;

	count = 0;
	j = 0;
	if (fl->precision < ft_unicodesize(i) && fl->precision != -1)
		j = fl->minwidth - fl->precision;
	else
		j = fl->minwidth - ft_unicodesize(i);
	if (fl->minwidth != 0 && j > 0)
	{
		fl->zero == 1 ? ft_putzero(j) : ft_putspace(j);
		(fl->precision != 0) ? ft_putuni(i, count, fl) : 0;
		return (fl->minwidth);
	}
	else
		return (ft_putuni(i, count, fl));
}
