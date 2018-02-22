#include "ft_printf.h"

int ft_is_d(intmax_t i, t_flag *fl)
{
	int count;
	char *res;
	int 	minus;

	count = 0;
	minus = 0;

	if (fl->h == 1)
		i = (short)i;
	else if (fl->h == 2)
		i = (signed char)i;
	else if (fl->l == 1)
		i = (long)i;
	else if (fl->l == 2)
		i = (long long)i;
	else if (fl->j== 1)
		i = (intmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (int)i;
    if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1  && i > 0 && fl->minus != 1)
    {
        count++;
        write(1, " ", 1);
    }
	if (fl->plus == 1 && i >= 0)
	{
		write(1, "+", 1);
		count++;
	}
	if (i < 0)
	{
		(fl->minwidth != 0) ? (minus = 1) : ft_putchr('-');
		count++;
		i = -i;
	}
	res = ft_itoa_base_s(i, 10);
	if (fl->minus == 1)
		count = ft_print_min(fl, res, count, minus);
	else
		count = ft_print(fl, res, count, minus);
	return (count);
}

int ft_is_d_big(intmax_t i, t_flag *fl)
{
	int count;
	char *res;
	int 	minus;

	minus = 0;
	count = 0;
	if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1 && i > 0)
	{
		count++;
		write(1, " ", 1);
	}
	else if (fl->l == 1)
		i = (long)i;
	else if (fl->l == 2)
		i = (long long)i;
	else if (fl->j== 1)
		i = (intmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (long)i;
	if (i < 0)
	{
		(fl->minwidth != 0) ? (minus = 1) : ft_putchr('-');
		count++;
		i = -i;
	}
	res = ft_itoa_base_s(i, 10);
	if (fl->minus == 1)
		count = ft_print_min(fl, res, count, minus);
	else
		count = ft_print(fl, res, count, minus);
	return (count);
}