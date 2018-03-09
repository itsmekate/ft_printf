/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:57:56 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/15 18:09:03 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_u(intmax_t i, t_flag *fl)
{
	int     count;
	char    *res;
	
	count = 0;
	if (fl->h == 1)
		i = (unsigned short)i;
	else if (fl->h == 2)
		i = (unsigned char)i;
	else if (fl->l == 1)
		i = (unsigned long)i;
	else if (fl->l == 2)
		i = (unsigned long long)i;
	else if (fl->j == 1)
		i = (uintmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	res = ft_itoa_base_s(i, 10);
	fl->plus = 0;
	if (fl->minus == 1)
		count += ft_print_min(fl, res, count, 0);
	else
		count += ft_print(fl, res, count, 0);
	return (count);
}

int ft_is_u_big(intmax_t i, t_flag *fl)
{
	int     count;
	char    *res;
	
	count = 0;
	if (fl->l == 1)
		i = (unsigned long)i;
	else if (fl->l == 2)
		i = (unsigned long long)i;
	else if (fl->j == 1)
		i = (uintmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (unsigned long)i;
	fl->plus = 0;
	res = ft_itoa_base_S(i, 10);
	if (fl->minus == 1)
		count += ft_print_min(fl, res, count, 0);
	else
		count += ft_print(fl, res, count, 0);
	return (count);
}


