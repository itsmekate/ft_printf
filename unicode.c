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
		write(1, "(null)" , 6);
		return (6);
	}
	if (fl->minus != 1)
		return (ft_printbigs(i, fl));
	else
		return (ft_printbigs_min(i, fl));

}

int ft_printbigs(wchar_t *i, t_flag *fl)
{
	int	count;
	int j = 0;

	count = 0;
//	if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1 && (count++))
//		write(1, " ", 1);
	j = fl->minwidth - ft_unicodesize(i);
	if (fl->minwidth != 0 && j > 0)
	{
        fl->zero == 1 ? ft_putzero(j) : ft_putspace(j);
		ft_putuni(i, count);
		return (fl->minwidth);
	}
	else
		return (ft_putuni(i, count));
}

int ft_printbigs_min(wchar_t *i, t_flag *fl)
{
	int	count;
	int j = 0;

	count = 0;
	if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1 && (count++))
		write(1, " ", 1);
	j = fl->minwidth - ft_unicodesize(i);
	if (fl->minwidth != 0 && j > 0)
	{
		ft_putuni(i, count);
        fl->zero == 1 ? ft_putzero(j) : ft_putspace(j);
		return (fl->minwidth);
	}
	else
		return (ft_putuni(i, count));
}

int ft_putuni(wchar_t *i, int count)
{
	while (*i)
	{
		count += print_unicode(*i);
		i++;
	}
	return (count);
}