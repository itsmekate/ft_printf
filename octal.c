
#include "ft_printf.h"

int ft_is_o(intmax_t i, t_flag *fl)
{
	int     count;
	char    *res;

	count = 0;
	if (i == 0 && fl->precision != 0)
	{
		ft_putchr('0');
		return (1);
	}
	// make additional function casting
	if (fl->h == 1)
		i = (unsigned short)i;
	else if (fl->h == 2)
		i = (unsigned char)i;
	else if (fl->l == 1)
		i = (unsigned long)i;
	else if (fl->l == 2)
		i = (long long)i;
	else if (fl->j== 1)
		i = (uintmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	res = ft_itoa_base_s(i, 8);
	if (fl->minus == 1)
		count = ft_print_octalmin(fl, res, count);
	else
		count = ft_print_octal(fl, res, count);
	return (count);
}

int	ft_is_o_big(intmax_t i, t_flag *fl)
{
	int		count;
	char	*res;

	count = 0;
	if (i == 0 && fl->precision != 0)
	{
		ft_putchr('0');
		return (1);
	}
	if (fl->h == 1)
		i = (unsigned short)i;
	else if (fl->l == 1)
		i = (unsigned long)i;
	else if (fl->l == 2)
		i = (long long)i;
	else if (fl->j== 1)
		i = (uintmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (long)i;
	res = ft_itoa_base_S(i, 8);
	if (fl->minus == 1)
		count = ft_print_octalmin(fl, res, count);
	else
		count = ft_print_octal(fl, res, count);
	return (count);
}

int ft_print_octal(t_flag *fl, char *res, int count)
{
	int j = 0;

	if ((fl->precision == 0 && ft_strcmp(res, "0") == 0))
		j = fl->minwidth;
	else if (fl->precision > ft_strlen(res))
		j = fl->minwidth - fl->precision;
	else
		j = fl->minwidth - ft_strlen(res);
	(fl->hash == 1 && fl->precision != 0) ? j-- : 0 ;
	if (fl->minwidth != 0 && j > 0)
	{
		(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
		(fl->hash == 1 && fl->precision != 0) ? write(1, "0", 1) : 0 ;
		if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") != 0)
		{
			fl->minwidth += fl->precision - ft_strlen(res) - 1;
			ft_putzero(fl->precision - ft_strlen(res));
			ft_putstr(res);
			free(res);
			return (fl->minwidth - 1);
		}
		if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") == 0)
		{
			free(res);
			return (fl->minwidth);
		}
		(fl->precision <= 0 && ft_strcmp(res, "0") == 0) ? 0 : ft_putstr(res);
		free(res);
		return (fl->minwidth);
	}
	else
	{
		(fl->hash == 1) ? (count += write(1, "0", 1)) : 0;
		if (fl->precision == 0 && ft_strcmp(res, "0") == 0)
		{
			free(res);
			return (count);
		}
		(fl->hash == 1 && fl->precision > 0) ? write(1, "0", 1) : 0 ;
		if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") != 0)
		{
			count += fl->precision - ft_strlen(res);
			ft_putzero(fl->precision - ft_strlen(res));
			count += ft_putstr(res);
			free(res);
			return (count);
		}
		if (fl->precision > ft_strlen(res) && ft_strcmp(res, "0") == 0)
		{
			free(res);
			return (fl->minwidth);
		}
		else
			count += ft_putstr(res);
		free(res);
		return (count);
	}
}

int ft_print_octalmin(t_flag *fl, char *res, int count)
{
	int j = 0;

	if (fl->precision > ft_strlen(res))
		j = fl->minwidth;
	else
		j = fl->minwidth - ft_strlen(res);
	if (fl->hash == 1 && (j--))
		write(1, "0", 1);
	if (fl->minwidth != 0 && j > 0)
	{
		if (fl->precision > ft_strlen(res))
		{
			fl->minwidth += fl->precision - ft_strlen(res) - 1;
			ft_putzero(fl->precision - ft_strlen(res));
			ft_putstr(res);
			j = fl->minwidth - ft_strlen(res) - 1;
			if (fl->minus != 1 || (fl->minwidth - fl->precision) > 0)
				(fl->zero == 1) ? ft_putzero(j) : ft_putspace(j);
		}
		else
		{
			ft_putstr(res);
			(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
		}
		free(res);
		return (fl->minwidth);
	}
	else
	{
		count += ft_putstr(res);
		free(res);
		return (count);
	}
}