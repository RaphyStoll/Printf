/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_select2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:33:39 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/02 09:33:47 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
/*Affichage d’un Unsigned Int (%u)*/
void ft_print_unsigned(unsigned int n)
{
    if (n >= 10)
        ft_print_unsigned(n / 10);
    ft_putchar((n % 10) + '0');
}