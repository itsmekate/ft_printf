/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:08:25 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/15 17:15:52 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_seven(int i, unsigned char res)
{
	res = i;
	write(1, &res, 1);
	return (1);
}

int	ft_eleven(int i)
{
	ft_putchr((i >> 6) | 192);
	ft_putchr((i & 0x3F) | 128);
	return (2);
}

int	ft_sixteen(int i)
{
	ft_putchr((i >> 12) | 224);
	ft_putchr(((i >> 6) & 0x3F) | 128);
	ft_putchr((i & 0x3F) | 128);
	return (3);
}

int	ft_more(int i)
{
	ft_putchr((i >> 18) | 240);
	ft_putchr(((i >> 12) & 0x3F) | 128);
	ft_putchr(((i >> 6) & 0x3F) | 128);
	ft_putchr((i & 0x3F) | 128);
	return (4);
}

int	print_unicode(unsigned int i)
{
	wchar_t		res;
	int			count;

	res = 0;
	count = 0;
	if (i <= 0x7F)
		count += ft_seven(i, res);
	else if (i <= 0x7FF)
		count += ft_eleven(i);
	else if (i <= 0xFFFF)
		count += ft_sixteen(i);
	else
		count += ft_more(i);
	return (count);
}
