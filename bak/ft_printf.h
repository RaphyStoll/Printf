/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:17:45 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/04 16:17:49 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/* Déclarations des fonctions d'affichage */
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_print_percent(void);
int	ft_print_pointer(void *ptr);
int	ft_print_hex_lower(unsigned int n);
int	ft_print_hex_upper(unsigned int n);
int	ft_print_hex_long(unsigned long n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_integer(int n);
int	ft_print_string(char *str);
int	ft_print_char(char c);

/* Déclarations des fonctions principales */
int	ft_printf(const char *format, ...);
int	ft_parse_format(const char *format, va_list args);
int	ft_handle_specifier(const char *format, va_list args);

#endif