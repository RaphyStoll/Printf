/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:38:00 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 19:29:19 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Note sur l'optimisation :
** La libc utilise souvent SWAR (SIMD Within A Register) pour lire
** 8 octets a la fois (sur 64 bits).
** Ici, on reste sur une implementation simple et propre pour la portabilite
** et la maintenance.
** On utilise des pointeurs pour eviter l'indexation (str[i]).
*/
size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
