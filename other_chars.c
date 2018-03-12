/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:22:31 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 18:25:01 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchr(int c)
{
	write(1, &c, 1);
}

void		ft_putnbr(ssize_t n)
{
	if (n < 0)
	{
		ft_putchr('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchr(n + 48);
}

char		*ft_strchr(const char *s, int c)
{
	char	a;
	char	*b;

	b = (char*)s;
	a = (char)c;
	while (*b || (*b == a))
	{
		if (*b == a)
			return (b);
		b++;
	}
	return (NULL);
}

int			ft_num_len(long long n)
{
	int			count;
	long long	len;

	count = 0;
	len = n;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n >= 0 && n <= 9)
		count++;
	else
	{
		while (len != 0)
		{
			len /= 10;
			count++;
		}
	}
	return (count);
}

int			ft_other_chars(char c, int count, t_flag fl)
{
	if (fl.minwidth != 0 && fl.zero == 1 && fl.minus != 1)
	{
		ft_putzero(fl.minwidth - 1);
		ft_putchr(c);
		count = fl.minwidth;
	}
	else if (fl.minwidth != 0 && fl.minus != 1)
	{
		ft_putspace(fl.minwidth - 1);
		ft_putchr(c);
		count = fl.minwidth;
	}
	else if (fl.minwidth != 0 && fl.minus == 1 && fl.zero == 1)
	{
		ft_putchr(c);
		ft_putzero(fl.minwidth - 1);
		count = fl.minwidth;
	}
	else if (fl.minwidth != 0 && fl.minus == 1)
	{
		ft_putchr(c);
		ft_putspace(fl.minwidth - 1);
		count = fl.minwidth;
	}
	return (count);
}
