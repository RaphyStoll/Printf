/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:19:51 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/09/22 22:08:32 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_printf : Fonction principale qui gère le formatage.
	•	ft_parse_format : Parcourt la chaîne de format et identifie les spécificateurs.
	•	ft_handle_specifier : Gère chaque spécificateur individuel.
	•	Fonctions pour chaque spécificateur :
	•	ft_print_char pour %c
	•	ft_print_string pour %s
	•	ft_print_integer pour %d et %i
	•	ft_print_unsigned pour %u
	•	ft_print_hex_lower pour %x
	•	ft_print_hex_upper pour %X
	•	ft_print_pointer pour %p
	•	ft_print_percent pour %%
	•	Fonctions utilitaires :
	•	ft_putchar
	•	ft_putstr
	•	ft_putnbr
	•	ft_putnbr_base*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
//! utils

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}
/*Affichage du Pourcentage (%%)*/
void ft_print_percent(void)
{
    ft_putchar('%');
}
/*Affichage d’un Pointeur (%p)*/
void ft_print_pointer(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    ft_putstr("0x");
    ft_print_hex_lower(addr);
}
/*Affichage en Hexadécimal (%x et %X)*/
void ft_print_hex_lower(unsigned int n)
{
    char *hex = "0123456789abcdef";
    if (n >= 16)
        ft_print_hex_lower(n / 16);
    ft_putchar(hex[n % 16]);
}
void ft_print_hex_upper(unsigned int n)
{
    char *hex = "0123456789ABCDEF";
    if (n >= 16)
        ft_print_hex_upper(n / 16);
    ft_putchar(hex[n % 16]);
}
/*Affichage d’un Unsigned Int (%u)*/
void ft_print_unsigned(unsigned int n)
{
    if (n >= 10)
        ft_print_unsigned(n / 10);
    ft_putchar((n % 10) + '0');
}
/*Affichage d’un Entier (%d ou %i)*/
void ft_print_integer(int n)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        ft_print_integer(n / 10);
    ft_putchar((n % 10) + '0');
}
/*Affichage d’une Chaîne (%s)*/
void ft_print_string(char *str)
{
    if (!str)
        str = "(null)";
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}
/*Affichage d’un Caractère (%c)*/
void ft_print_char(char c)
{
    ft_putchar(c);
}
/*fonction principale*/
void ft_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    ft_parse_format(format, args);
    va_end(args);
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

int main()
{
	char a = 'a';
	char *b = "Hello World!";
	int c = 42;
	unsigned int d = 4294967268;
	int e = 255;
	int *f = 0;
	
    ft_printf("Caractère : %c\n", a);
    ft_printf("Chaîne : %s\n", b);
    ft_printf("Entier d: %d\n", c);
	ft_printf("Entier i: %i\n", c);
    ft_printf("Unsigned : %u\n", d);
    ft_printf("Hexadecimal (minuscule) : %x\n", e);
    ft_printf("Hexadecimal (majuscule) : %X\n", e);
	printf("printf Pointeur : %p\n",f);
    ft_printf("ft_printf Pointeur : %p\n", f);
    ft_printf("Pourcentage : %%\n");
    return 0;
}
