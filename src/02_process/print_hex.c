#include "../../includes/ft_printf.h"

static int	hex_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	puthex(unsigned int n, const char type, t_print *tab)
{
	char	*base;

	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		puthex(n / 16, type, tab);
	tab->tl += write(1, &base[n % 16], 1);
}

void	print_hex(t_print *tab, const char type)
{
	unsigned int	n;
	int				len;
	int				zeros;
	int				spaces;

	n = va_arg(tab->args, unsigned int);
	len = hex_len(n);
	if (n == 0 && tab->pnt && tab->prc == 0)
		len = 0;
	zeros = 0;
	if (tab->pnt && tab->prc > len)
		zeros = tab->prc - len;
	if (tab->zero && !tab->pnt && !tab->dash && tab->wdt > len + (tab->hash && n ? 2 : 0))
		zeros = tab->wdt - len - (tab->hash && n ? 2 : 0);
	spaces = 0;
	if (tab->wdt > len + zeros + (tab->hash && n ? 2 : 0))
		spaces = tab->wdt - (len + zeros + (tab->hash && n ? 2 : 0));
	if (!tab->dash)
		while (spaces-- > 0)
			tab->tl += write(1, " ", 1);
	if (tab->hash && n)
	{
		if (type == 'X')
			tab->tl += write(1, "0X", 2);
		else
			tab->tl += write(1, "0x", 2);
	}
	while (zeros-- > 0)
		tab->tl += write(1, "0", 1);
	if (len > 0)
		puthex(n, type, tab);
	if (tab->dash)
		while (spaces-- > 0)
			tab->tl += write(1, " ", 1);
}

static int	ptr_len(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	putptr(unsigned long n, t_print *tab)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		putptr(n / 16, tab);
	tab->tl += write(1, &base[n % 16], 1);
}

void	print_ptr(t_print *tab)
{
	unsigned long	n;
	int				len;
	int				spaces;

	n = va_arg(tab->args, unsigned long);
	len = ptr_len(n);
	spaces = 0;
	if (tab->wdt > len + 2)
		spaces = tab->wdt - (len + 2);
	if (!tab->dash)
		while (spaces-- > 0)
			tab->tl += write(1, " ", 1);
	tab->tl += write(1, "0x", 2);
	putptr(n, tab);
	if (tab->dash)
		while (spaces-- > 0)
			tab->tl += write(1, " ", 1);
}
