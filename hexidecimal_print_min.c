/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexidecimal_print_min.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:28:13 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 20:28:15 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_min_width(t_flag *fl, char *res, int j)
{
	if (fl->precision > ft_strlen(res))
	{
		fl->minwidth += fl->precision - ft_strlen(res) - 1;
		ft_putzero(fl->precision - ft_strlen(res));
		ft_putstr(res);
		j = fl->minwidth - ft_strlen(res) - 1;
		if (fl->minus != 1 || (fl->minwidth - fl->precision) > 0)
			(fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
	}
	else
	{
		ft_putstr(res);
		(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
	}
}

int		ft_print_hexmin(t_flag *fl, char *res, int count)
{
	int j;

	if (fl->precision > ft_strlen(res))
		j = fl->minwidth;
	else
		j = fl->minwidth - ft_strlen(res);
	if (fl->hash == 1 && (j -= 2))
		write(1, "0x", 2);
	if (fl->minwidth != 0 && j > 0)
	{
		print_hex_min_width(fl, res, j);
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
