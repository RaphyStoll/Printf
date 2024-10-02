/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_select1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:33:54 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/02 09:33:59 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
