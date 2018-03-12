#include "ft_printf.h"

int ft_print_hex(t_flag *fl, char *res, int count, int big)
{

	int j = 0;

	if ((fl->precision == 0 && ft_strcmp(res, "0") == 0))
		j = fl->minwidth;
	else if (fl->precision > ft_strlen(res))
		j = fl->minwidth - fl->precision;
	else
		j = fl->minwidth - ft_strlen(res);
	(fl->hash == 1 && fl->precision != 0) ? j-= 2 : 0 ;
	if (fl->minwidth != 0 && j > 0)
	{
		if (fl->zero == 1 && fl->minus != 1)
		{
			(fl->hash == 1 && big && fl->precision != 0) ? write(1, "0X", 2) : 0 ;
			(fl->hash == 1 && !big && fl->precision != 0) ? write(1, "0x", 2) : 0 ;
			ft_putzero(j);
		}
		else
		{
			ft_putspace(j);
			(fl->hash == 1 && big && fl->precision != 0) ? write(1, "0X", 2) : 0 ;
			(fl->hash == 1 && !big && fl->precision != 0) ? write(1, "0x", 2) : 0 ;
		}
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
		(fl->hash == 1 && big && fl->precision != 0 && fl->precision > 0) ? write(1, "0X", 2) : 0 ;
		(fl->hash == 1 && !big && fl->precision != 0 && fl->precision > 0) ? write(1, "0x", 2) : 0 ;
		(fl->precision <= 0 && ft_strcmp(res, "0") == 0) ? 0 : ft_putstr(res);
		free(res);
		return (fl->minwidth);
	}
	else
	{
		(fl->hash == 1 && big && ft_strcmp(res, "0") != 0) ? (count += write(1, "0X", 2)) : 0;
		(fl->hash == 1 && !big && ft_strcmp(res, "0") != 0) ? (count += write(1, "0x", 2)) : 0;
		if (fl->precision == 0 && ft_strcmp(res, "0") == 0)
		{
			free(res);
			return (count);
		}
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

int ft_print_hexmin(t_flag *fl, char *res, int count)
{
	int j = 0;

	if (fl->precision > ft_strlen(res))
		j = fl->minwidth;
	else
		j = fl->minwidth - ft_strlen(res);
	if (fl->hash == 1 && (j-= 2))
		write(1, "0x", 2);
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