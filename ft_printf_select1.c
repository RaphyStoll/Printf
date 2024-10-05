/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_select1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:18:14 by raphaelferr       #+#    #+#             */
/*   Updated: 2024/10/04 16:26:02 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Affiche un caractère de pourcentage (%%) et retourne le nombre de 
 * caractères affichés.
 * Cette fonction affiche le caractère '%' sur la sortie standard et retourne 1.
 * @return int Le nombre de caractères affichés (toujours 1).
 */
int	ft_print_percent(void)
{
	return (ft_putchar('%'));
}

/**
 * @brief Affiche un pointeur (%p) et retourne le nombre de caractères affichés.
 * Cette fonction convertit l'adresse du pointeur en hexadécimal, préfixe avec
 * "0x",
 * et affiche le tout. Elle utilise une fonction spécifique pour gérer les
 * adresses de type unsigned long.
 * @param ptr Le pointeur à afficher.
 * @return int Le nombre de caractères affichés.
 */
int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;
	int				count;

	count = 0;
	addr = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_print_hex_long(addr);
	return (count);
}

/**
 * @brief Affiche un nombre entier non signé en hexadécimal en minuscules (%x) et
 * retourne le nombre de caractères affichés.
 * Cette fonction convertit un entier non signé en hexadécimal en utilisant des
 * lettres minuscules,
 * affiche le tout et retourne le nombre de caractères affichés.
 * @param n L'entier non signé à afficher en hexadécimal.
 * @return int Le nombre de caractères affichés.
 */
int	ft_print_hex_lower(unsigned int n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_print_hex_lower(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

/**
 * @brief Affiche un nombre entier non signé en hexadécimal en majuscules (%X) et
 * retourne le nombre de caractères affichés.
 * Cette fonction convertit un entier non signé en hexadécimal en utilisant des
 * lettres majuscules,
 * affiche le tout et retourne le nombre de caractères affichés.
 * @param n L'entier non signé à afficher en hexadécimal.
 * @return int Le nombre de caractères affichés.
 */
int	ft_print_hex_upper(unsigned int n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_print_hex_upper(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

/**
 * @brief Affiche un nombre entier non signé en hexadécimal (pour les pointeurs)
 * en minuscules et retourne le nombre de caractères affichés.
 * Cette fonction est similaire à ft_print_hex_lower, mais elle prend
 * un unsigned long pour
 * gérer les adresses mémoire complètes. Elle est utilisée spécifiquement pour
 * afficher les pointeurs.
 * @param n L'entier non signé à afficher en hexadécimal (adresse mémoire).
 * @return int Le nombre de caractères affichés.
 */
int	ft_print_hex_long(unsigned long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_print_hex_long(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
