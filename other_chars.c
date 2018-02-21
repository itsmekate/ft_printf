#include "ft_printf.h"

int ft_other_chars(char c, int count, t_flag fl)
{
    if (fl.minwidth != 0 && fl.zero == 1 && fl.minus != 1)
    {
        ft_putzero(fl.minwidth - 1);
        ft_putchr(c);
        count = fl.minwidth;
    }
    else if (fl.minwidth != 0 && fl.minus != 1)
    {
        ft_putspace(fl.minwidth - 1);
        ft_putchr(c);
        count = fl.minwidth;
    }
    else if (fl.minwidth != 0 && fl.minus == 1 && fl.zero == 1)
    {
        ft_putchr(c);
        ft_putzero(fl.minwidth - 1);
        count = fl.minwidth;
    }
    else if (fl.minwidth != 0 && fl.minus == 1)
    {
        ft_putchr(c);
        ft_putspace(fl.minwidth - 1);
        count = fl.minwidth;
    }
    return (count);
}