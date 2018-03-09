/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:27 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/03 18:37:29 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}

char *ft_itoa_base_s(uintmax_t value, int base)
{
	int             i;
	uintmax_t        v;
	char            *result;
	unsigned int    a;
	char            *bases;

	i = 0;
	v = value;
	a = base;
	bases = "0123456789abcdef";
	if (base > 16 || base < 2)
		return (NULL);
	if (value == 0)
	{
		result = ft_strnew(1);
		result[0] = '0';
		return (result);
	}
	while (v /= a)
		i++;
	i++;
	result = ft_strnew(i);
	i--;
	while (value != 0)
	{
		result[i] = bases[value % base];
		value /= base;
		i--;
	}
	return (result);
 }

char *ft_itoa_base_S(uintmax_t value, int base)
{
	int             i;
	uintmax_t        v;
	char            *result;
	unsigned int    a;
	char            *bases;

	i = 0;
	v = value;
	a = base;
	bases = "0123456789ABCDEF";
	if (base > 16 || base < 2)
		return (NULL);
	if (value == 0)
	{
		result = ft_strnew(1);
		result[0] = '0';
		return (result);
	}
	while (v /= a)
		i++;
	i++;
	result = ft_strnew(i);
	i--;
	while (value != 0)
	{
		result[i] = bases[value % base];
		value /= base;
		i--;
	}
	return (result);
}