/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:28:16 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/04 16:30:26 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/**
 * @brief Fonction principale qui imite le comportement de printf.
 * Cette fonction prend une chaîne de format et un nombre variable d'arguments,
 * parse la chaîne de format et affiche les arguments en conséquence.
 * Elle retourne le nombre total de caractères imprimés.
 * @param format La chaîne de format.
 * @return int Le nombre total de caractères imprimés, ou -1 si le format est
 * NULL.
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_parse_format(format, args);
	va_end(args);
	return (count);
}

/**
 * @brief Parcourt la chaîne de format et gère les spécificateurs.
 *
 * Cette fonction parcourt la chaîne de format caractère par caractère.
 * Lorsqu'elle rencontre un '%', elle appelle ft_handle_specifier pour traiter
 * le spécificateur suivant. Sinon, elle affiche le caractère actuel.
 * @param format La chaîne de format à parser.
 * @param args La liste des arguments variadiques.
 * @return int Le nombre total de caractères imprimés.
 */
int	ft_parse_format(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_handle_specifier(&format[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	return (count);
}

/**
 * @brief Gère les spécificateurs de format et appelle les fonctions appropriées.
 * Cette fonction identifie le spécificateur de format et appelle la fonction
 * correspondante pour afficher l'argument. Elle accumule le nombre de caractères
 * imprimés par chaque appel de fonction.
 * @param format Le spécificateur de format (caractère après '%').
 * @param args La liste des arguments variadiques.
 * @return int Le nombre de caractères imprimés par le spécificateur, ou 0
 * si non reconnu.
 */
int	ft_handle_specifier(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (*format == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_print_integer(va_arg(args, int));
	else if (*format == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (*format == 'X')
		count += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (*format == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else if (*format == '%')
		count += ft_print_percent();
	else
		return (0);
	return (count);
}
