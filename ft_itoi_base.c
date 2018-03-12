/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:27 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 17:57:26 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, size + 1);
	return (s);
}

void		loop_small(uintmax_t value, int base, char *result, int i)
{
	char	*bases;

	bases = "0123456789abcdef";
	while (value != 0)
	{
		result[i] = bases[value % base];
		value /= base;
		i--;
	}
}

void		loop_big(uintmax_t value, int base, char *result, int i)
{
	char	*bases;

	bases = "0123456789ABCDEF";
	while (value != 0)
	{
		result[i] = bases[value % base];
		value /= base;
		i--;
	}
}

char		*ft_itoa_base_s(uintmax_t value, int base)
{
	int				i;
	uintmax_t		v;
	char			*result;
	unsigned int	a;

	i = 0;
	v = value;
	a = base;
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
	loop_small(value, base, result, i);
	return (result);
}

char		*ft_itoa_base_s_big(uintmax_t value, int base)
{
	int				i;
	uintmax_t		v;
	char			*result;
	unsigned int	a;

	i = 0;
	v = value;
	a = base;
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
	loop_big(value, base, result, i);
	return (result);
}
