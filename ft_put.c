/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:15 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/15 17:24:42 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchr(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(ssize_t n)
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

//int		ft_num_len(long long n)
//{
//	int			count;
//	long long	len;
//
//	count = 0;
//	len = n;
//	if (n < 0)
//	{
//		count++;
//		n = -n;
//	}
//	if (n >= 0 && n <= 9)
//		count++;
//	else
//	{
//		while (len != 0)
//		{
//			len /= 10;
//			count++;
//		}
//	}
//	return (count);
//}

int 	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

int ft_putstr(char *str)
{
    size_t i;

    i = (size_t)ft_strlen(str);
    write(1, str, i);
	return ((int)i);
}

void    ft_putzero(int j)
{
    while (j--)
        ft_putchr('0');
}

void    ft_putspace(int j)
{
    while (j--)
        ft_putchr(' ');
}