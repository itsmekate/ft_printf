#include "ft_printf.h"

int ft_is_x(intmax_t i, t_flag *fl)
{
    int     count;
    char    *res;

    count = 0;
    if (i == 0 && fl->precision != 0)
    {
        ft_putchr('0');
        return (1);
    }
    if (fl->h == 1)
        i = (unsigned short)i;
    else if (fl->h == 2)
        i = (unsigned char)i;
    else if (fl->l == 1)
        i = (unsigned long)i;
    else if (fl->l == 2)
        i = (unsigned long long)i;
    else if (fl->j == 1)
        i = (uintmax_t)i;
    else if (fl->z == 1)
        i = (size_t)i;
    else
        i = (unsigned int)i;
    res = ft_itoa_base_s(i, 16);
    if (fl->minus == 1)
        count = ft_print_hexmin(fl, res, count);
    else
        count = ft_print_hex(fl, res, count);
    return (count);
}

int	ft_is_x_big(intmax_t i, t_flag *fl)
{
    int     count;
    char    *res;

    count = 0;
    if (i == 0 && fl->precision != 0)
    {
        ft_putchr('0');
        return (1);
    }
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
    res = ft_itoa_base_S(i, 16);
    if (fl->hash == 1 && (count += 2))
        write(1, "0X", 2);
    if (fl->minus == 1)
        count = ft_print_min(fl, res, count, 0);
    else
        count = ft_print(fl, res, count, 0);
    return (count);
}
//needs shortening
int ft_print_hex(t_flag *fl, char *res, int count)
{
    int j;

    if ((fl->precision == 0 && ft_strcmp(res, "0") == 0))
    {
        j = fl->minwidth;
    }
    else
        j = fl->minwidth - ft_strlen(res);
    (fl->hash == 1 && ft_strcmp(res, "0") != 0) ? j -= 2 : 0 ;
    if (fl->minwidth != 0 && j > 0)
    {
        if (fl->zero == 1 && fl->minus != 1)
        {
            (fl->hash == 1 && ft_strcmp(res, "0") != 0) ? write(1, "0x", 2) : 0 ;
            ft_putzero(j);
        }
        else
        {
            ft_putspace(j);
            (fl->hash == 1  && ft_strcmp(res, "0") != 0) ? write(1, "0x", 2) : 0 ;
        }
        (fl->precision == 0 && ft_strcmp(res, "0") == 0) ? 0 : ft_putstr(res);
//        ft_putstr(res);
        free(res);
        return (fl->minwidth);
    }
    else
    {
        if (fl->hash == 1 && ft_strcmp(res, "0") != 0)
        {
            write(1, "0x", 2);
            count += 2;
        }
        (fl->precision == 0 && ft_strcmp(res, "0") == 0) ? 0 : (count += ft_putstr(res));
//         ft_strlen(res);
        free(res);
        return (count);
    }
}

int ft_print_hexmin(t_flag *fl, char *res, int count)
{
    int j = 0;

    j = fl->minwidth - ft_strlen(res);
    if (fl->hash == 1)
        j -= 2;
    if (fl->minwidth != 0 && j > 0)
    {
        if (fl->hash == 1)
            write(1, "0x", 2);
        ft_putstr(res);
        (fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
        free(res);
        return (fl->minwidth);
    }
    else
    {
        if (fl->hash == 1)
        {
            write(1, "0x", 2);
            count += 2;
        }
        count += ft_putstr(res);
        free(res);
        return (count);
    }
}