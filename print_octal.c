/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:06:12 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 19:07:27 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_octal(intmax_t i, t_flag *fl)
{
	int		count;
	char	*res;

	count = 0;
	res = ft_itoa_base_s(i, 8);
	if (fl->minus == 1)
		count = ft_print_octalmin(fl, res, count);
	else
		count = ft_print_octal(fl, res, count);
	return (count);
}

int	ft_is_o(intmax_t i, t_flag *fl)
{
	if (i == 0 && fl->precision != 0)
		return ((int)write(1, "0", 1));
	if (fl->h == 1)
		i = (unsigned short)i;
	else if (fl->h == 2)
		i = (unsigned char)i;
	else if (fl->l == 1)
		i = (unsigned long)i;
	else if (fl->l == 2)
		i = (long long)i;
	else if (fl->j == 1)
		i = (uintmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	return (print_octal(i, fl));
}

int	ft_is_o_big(intmax_t i, t_flag *fl)
{
	int		count;
	char	*res;

	count = 0;
	if (i == 0 && fl->precision != 0)
		return ((int)write(1, "0", 1));
	if (fl->h == 1)
		i = (unsigned short)i;
	else if (fl->l == 1)
		i = (unsigned long)i;
	else if (fl->l == 2)
		i = (long long)i;
	else if (fl->j == 1)
		i = (uintmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (long)i;
	res = ft_itoa_base_s_big(i, 8);
	if (fl->minus == 1)
		count = ft_print_octalmin(fl, res, count);
	else
		count = ft_print_octal(fl, res, count);
	return (count);
}
