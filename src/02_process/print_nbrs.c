#include "../../includes/ft_printf.h"

static int	nbr_len(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	putnbr_rec(long n, t_print *tab)
{
	char	c;

	if (n < 0)
		n = -n;
	if (n >= 10)
		putnbr_rec(n / 10, tab);
	c = (n % 10) + '0';
	tab->tl += write(1, &c, 1);
}

void	print_nbr(t_print *tab)
{
	long	n;
	int		len;
	int		zeros;
	int		spaces;

	n = va_arg(tab->args, int);
	len = nbr_len(n);
	if (n == 0 && tab->pnt && tab->prc == 0)
		len = 0;
	zeros = 0;
	if (tab->pnt && tab->prc > len)
		zeros = tab->prc - len;
	if (tab->zero && !tab->pnt && !tab->dash && tab->wdt > len + (n < 0 || tab->sign || tab->sp))
		zeros = tab->wdt - len - (n < 0 || tab->sign || tab->sp);
	spaces = 0;
	if (tab->wdt > len + zeros + (n < 0 || tab->sign || tab->sp))
		spaces = tab->wdt - (len + zeros + (n < 0 || tab->sign || tab->sp));
	if (!tab->dash)
		while (spaces-- > 0)
			tab->tl += write(1, " ", 1);
	if (n < 0)
		tab->tl += write(1, "-", 1);
	else if (tab->sign)
		tab->tl += write(1, "+", 1);
	else if (tab->sp)
		tab->tl += write(1, " ", 1);
	while (zeros-- > 0)
		tab->tl += write(1, "0", 1);
	if (len > 0)
		putnbr_rec(n, tab);
	if (tab->dash)
		while (spaces-- > 0)
			tab->tl += write(1, " ", 1);
}

static int	unbr_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	putunbr_rec(unsigned int n, t_print *tab)
{
	char	c;

	if (n >= 10)
		putunbr_rec(n / 10, tab);
	c = (n % 10) + '0';
	tab->tl += write(1, &c, 1);
}

void	print_unsigned(t_print *tab)
{
	unsigned int	n;
	int				len;
	int				zeros;
	int				spaces;

	n = va_arg(tab->args, unsigned int);
	len = unbr_len(n);
	if (n == 0 && tab->pnt && tab->prc == 0)
		len = 0;
	zeros = 0;
	if (tab->pnt && tab->prc > len)
		zeros = tab->prc - len;
	if (tab->zero && !tab->pnt && !tab->dash && tab->wdt > len)
		zeros = tab->wdt - len;
	spaces = 0;
	if (tab->wdt > len + zeros)
		spaces = tab->wdt - (len + zeros);
	if (!tab->dash)
		while (spaces-- > 0)
			tab->tl += write(1, " ", 1);
	while (zeros-- > 0)
		tab->tl += write(1, "0", 1);
	if (len > 0)
		putunbr_rec(n, tab);
	if (tab->dash)
		while (spaces-- > 0)
			tab->tl += write(1, " ", 1);
}
