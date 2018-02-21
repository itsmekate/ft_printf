#include "ft_printf.h"

int ft_print_pointmin(t_flag *fl, char *res, int count)
{
    int j = 0;

    j = fl->minwidth - ft_strlen(res) - 2;
    if (fl->minwidth != 0 && j > 0)
    {
        write(1, "0x", 2);
        ft_putstr(res);
        (fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
        free(res);
        return (fl->minwidth);
    }
    else
    {
        write(1, "0x", 2);
        count += 2;
        count += ft_putstr(res);
        free(res);
        return (count);
    }
}

int ft_print_point(t_flag *fl, char *res, int count)
{
    int j;

    j = fl->minwidth - ft_strlen(res) - 2;
    if (fl->minwidth != 0 && j > 0)
    {
        if (fl->zero == 1 && fl->minus != 1)
        {
            write(1, "0x", 2);
            ft_putzero(j);
        }
        else
        {
            ft_putspace(j);
            write(1, "0x", 2);
        }
        ft_putstr(res);
        free(res);
        return (fl->minwidth);
    }
    else
    {
        count += write(1, "0x", 2);
        count += ft_putstr(res);
        free(res);
        return (count);
    }
}

int ft_is_p(intmax_t i, t_flag *fl)
{
	int     count;
	char    *res;

	count = 0;
	res = ft_itoa_base_s(i, 16);
//	count += write(1, "0x", 2);
	if (fl->minus != 1)
		count += ft_print_point(fl, res, count);
	else
		count += ft_print_pointmin(fl, res, count);
	return (count);
}