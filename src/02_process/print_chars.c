#include "../../includes/ft_printf.h"

void	print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->wdt && !tab->dash)
		while (--tab->wdt > 0)
			tab->tl += write(1, " ", 1);
	tab->tl += write(1, &c, 1);
	if (tab->wdt && tab->dash)
		while (--tab->wdt > 0)
			tab->tl += write(1, " ", 1);
}

void	print_str(t_print *tab)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (tab->pnt && tab->prc < len)
		len = tab->prc;
	if (tab->wdt && !tab->dash)
		while (tab->wdt-- > len)
			tab->tl += write(1, " ", 1);
	i = 0;
	while (i < len)
		tab->tl += write(1, &str[i++], 1);
	if (tab->wdt && tab->dash)
		while (tab->wdt-- > len)
			tab->tl += write(1, " ", 1);
}

void	print_percent(t_print *tab)
{
	if (tab->wdt && !tab->dash)
	{
		if (tab->zero)
			while (--tab->wdt > 0)
				tab->tl += write(1, "0", 1);
		else
			while (--tab->wdt > 0)
				tab->tl += write(1, " ", 1);
	}
	tab->tl += write(1, "%", 1);
	if (tab->wdt && tab->dash)
		while (--tab->wdt > 0)
			tab->tl += write(1, " ", 1);
}
