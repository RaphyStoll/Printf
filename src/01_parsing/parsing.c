/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:42:00 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/12/29 20:38:05 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../libs/libft/includes/libft.h"

static int	parse_flags(t_print *tab, const char *format, int pos);
static int	parse_width(t_print *tab, const char *format, int pos);
static int	parse_precision(t_print *tab, const char *format, int pos);
static void	parse_conversion(t_print *tab, const char type);

/*
** Evalue le format apres un %.
** Gere les flags, la largeur, la precision et la conversion.
** Retourne la position apres le format traite.
*/
int	eval_format(t_print *tab, const char *format, int pos)
{
	initialise_tab(tab);
	pos = parse_flags(tab, format, pos);
	pos = parse_width(tab, format, pos);
	pos = parse_precision(tab, format, pos);
	parse_conversion(tab, format[pos]);
	return (pos);
}

static int	parse_flags(t_print *tab, const char *format, int pos)
{
	while (1)
	{
		if (format[pos] == '-')
			tab->dash = 1;
		else if (format[pos] == '0')
			tab->zero = 1;
		else if (format[pos] == '#')
			tab->hash = 1;
		else if (format[pos] == ' ')
			tab->sp = 1;
		else if (format[pos] == '+')
			tab->sign = 1;
		else
			break ;
		pos++;
	}
	return (pos);
}

static int	parse_width(t_print *tab, const char *format, int pos)
{
	if (format[pos] == '*')
	{
		tab->wdt = va_arg(tab->args, int);
		if (tab->wdt < 0)
		{
			tab->dash = 1;
			tab->wdt *= -1;
		}
		pos++;
	}
	else
	{
		tab->wdt = ft_atoi(&format[pos]);
		while (ft_isdigit(format[pos]))
			pos++;
	}
	return (pos);
}

static int	parse_precision(t_print *tab, const char *format, int pos)
{
	if (format[pos] == '.')
	{
		tab->pnt = 1;
		pos++;
		if (format[pos] == '*')
		{
			tab->prc = va_arg(tab->args, int);
			pos++;
		}
		else
		{
			tab->prc = ft_atoi(&format[pos]);
			while (ft_isdigit(format[pos]))
				pos++;
		}
	}
	return (pos);
}

static void	parse_conversion(t_print *tab, const char type)
{
	if (type == 'c')
		print_char(tab);
	else if (type == 's')
		print_str(tab);
	else if (type == 'p')
		print_ptr(tab);
	else if (type == 'd' || type == 'i')
		print_nbr(tab);
	else if (type == 'u')
		print_unsigned(tab);
	else if (type == 'x' || type == 'X')
		print_hex(tab, type);
	else if (type == '%')
		print_percent(tab);
}
