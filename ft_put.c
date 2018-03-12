/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:15 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 18:26:33 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(char *str)
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

int			ft_putstr(char *str)
{
	size_t i;

	i = (size_t)ft_strlen(str);
	write(1, str, i);
	return ((int)i);
}

void		ft_putzero(int j)
{
	while (j--)
		ft_putchr('0');
}

void		ft_putspace(int j)
{
	while (j--)
		ft_putchr(' ');
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char*)b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
