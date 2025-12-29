/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_select2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:26:40 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/04 16:26:44 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Affiche un entier (spécificateurs %d ou %i) et retourne le nombre
 * de caractères affichés.
 * Cette fonction gère les entiers négatifs en affichant un signe '-' et
 * convertit l'entier en positif.
 * Elle gère également l'entier le plus petit (-2147483648) sans provoquer
 * de débordement.
 * @param n L'entier à afficher.
 * @return int Le nombre de caractères affichés.
 */
int	ft_print_integer(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_print_integer(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

/**
 * @brief Affiche une chaîne de caractères (spécificateur %s) et retourne
 * le nombre de caractères affichés.
 * Si la chaîne passée est NULL, elle affiche "(null)" et retourne 6.
 * @param str La chaîne de caractères à afficher.
 * @return int Le nombre de caractères affichés.
 */
int	ft_print_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

/**
 * @brief Affiche un caractère (spécificateur %c) et retourne le nombre
 * de caractères affichés.
 * @param c Le caractère à afficher.
 * @return int Le nombre de caractères affichés (toujours 1).
 */
int	ft_print_char(char c)
{
	return (ft_putchar(c));
}

/**
 * @brief Affiche un entier non signé (spécificateur %u) et retourne le nombre
 * de caractères affichés.
 * @param n L'entier non signé à afficher.
 * @return int Le nombre de caractères affichés.
 */
int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
