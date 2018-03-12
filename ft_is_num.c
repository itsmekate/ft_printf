/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:28:42 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 19:29:08 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_count(intmax_t i, t_flag *fl, int count)
{
	if (fl->space == 1 && fl->minwidth == 0
		&& fl->plus != 1 && i > 0 && fl->minus != 1)
		count += ((int)write(1, " ", 1));
	if (i == 0 && fl->space == 1 && fl->minwidth != 0 && fl->zero == 1)
		count -= write(1, " ", 1);
	if (fl->plus == 1 && i >= 0)
		count++;
	return (count);
}

int			print_digit(intmax_t i, t_flag *fl, int count, int minus)
{
	char	*res;

	res = ft_itoa_base_s(i, 10);
	if (fl->minus == 1)
		count = ft_print_min(fl, res, count, minus);
	else
		count = ft_print(fl, res, count, minus);
	return (count);
}

intmax_t	cast(intmax_t i, t_flag *fl)
{
	if (fl->h == 1)
		i = (short)i;
	else if (fl->h == 2)
		i = (signed char)i;
	else if (fl->l == 1)
		i = (long)i;
	else if (fl->l == 2)
		i = (long long)i;
	else if (fl->j == 1)
		i = (intmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (int)i;
	return (i);
}

int			ft_is_d(intmax_t i, t_flag *fl)
{
	int		count;
	int		minus;

	minus = 0;
	i = cast(i, fl);
	count = check_count(i, fl, 0);
	if (i < 0)
	{
		minus = 1;
		count++;
		i = -i;
	}
	return (print_digit(i, fl, count, minus));
}

int			ft_is_d_big(intmax_t i, t_flag *fl)
{
	int		count;
	int		minus;

	minus = 0;
	count = 0;
	if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1 && i > 0)
		count += ((int)write(1, " ", 1));
	else if (fl->l == 1)
		i = (long)i;
	else if (fl->l == 2)
		i = (long long)i;
	else if (fl->j == 1)
		i = (intmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (long)i;
	if (i < 0)
	{
		minus = 1;
		count++;
		i = -i;
	}
	return (print_digit(i, fl, count, minus));
}
