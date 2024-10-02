/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:19:51 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/02 09:34:04 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*fonction principale*/
int ft_printf(const char *format, ...)
{
    va_list args;

	if (!format)
		return (-1);
    va_start(args, format);
    ft_parse_format(format, args);
    va_end(args);
	return (0);
}
/*fonction qui parcours ma string*/
//? i = compteur pour me deplacer dans la string 
void ft_parse_format(const char *format, va_list args)
{
    int i = 0;

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i += ft_handle_specifier(&format[i + 1], args);
            i++;
        }
        else
        {
            ft_putchar(format[i]);
            i++;
        }
    }
}

/*sert a selectionner le bon selecteur et lancer la fontion corespondante*/
int ft_handle_specifier(const char *format, va_list args)
{
    if (*format == 'c')
        ft_print_char(va_arg(args, int));
    else if (*format == 's')
        ft_print_string(va_arg(args, char *));
    else if (*format == 'd' || *format == 'i')
        ft_print_integer(va_arg(args, int));
    else if (*format == 'u')
        ft_print_unsigned(va_arg(args, unsigned int));
    else if (*format == 'x')
        ft_print_hex_lower(va_arg(args, unsigned int));
    else if (*format == 'X')
        ft_print_hex_upper(va_arg(args, unsigned int));
    else if (*format == 'p')
        ft_print_pointer(va_arg(args, void *));
    else if (*format == '%')
        ft_print_percent();
    else
        return 0;
    return 1;
}


