
#include "ft_printf.h"

int ft_is_o(intmax_t i, t_flag *fl)
{
    int     count;
    char    *res;

    count = 0;
    if (i == 0)
    {
        ft_putchr('0');
        return (1);
    }
    if (fl->space == 1 && fl->minwidth == 0 && fl->plus != 1)
    {
        count++;
        write(1, " ", 1);
    }
    // make additional function casting
    if (fl->h == 1)
        i = (unsigned short)i;
    else if (fl->h == 2)
        i = (unsigned char)i;
    else if (fl->l == 1)
        i = (unsigned long)i;
    else if (fl->l == 2)
        i = (unsigned long long)i;
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
    if (i == 0)
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
        i = (unsigned long long)i;
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

	j = fl->minwidth - ft_strlen(res);
	if (fl->hash == 1)
		j--;
	if (fl->minwidth != 0 && j > 0)
	{
        (fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
        if (fl->hash == 1)
            write(1, "0", 1);
		ft_putstr(res);
		free(res);
		return (fl->minwidth);
	}
	else
	{
		if (fl->hash == 1)
		{
			write(1, "0", 1);
			count++;
		}
		count += ft_putstr(res);
		free(res);
		return (count);
	}
}

int ft_print_octalmin(t_flag *fl, char *res, int count)
{
	int j = 0;

	j = fl->minwidth - ft_strlen(res);
	if (fl->hash == 1 && (j--))
		write(1, "0", 1);
	if (fl->minwidth != 0 && j > 0)
	{
		ft_putstr(res);
		(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
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