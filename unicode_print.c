#include "ft_printf.h"

int	ft_is_c_big(unsigned int i, t_flag *fl)
{
	int	count;

	count = print_unicode(i);
	return (count);
}

int	ft_is_s_big(wchar_t *i, t_flag *fl)
{
	if (i == NULL)
	{
		if (fl->precision != 0 && fl->precision != -1)
		{
			write(1, "(null)" , (size_t)fl->precision);
			return (fl->precision);
		}
		else
			write(1, "(null)" , 6);
		return (6);
	}
	if (fl->minus != 1)
		return (ft_printbigs(i, fl));
	else
		return (ft_printbigs_min(i, fl));

}