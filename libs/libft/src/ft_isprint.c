/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:35:00 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 19:21:55 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Optimisation :
** Les caracteres imprimables ASCII vont de 32 (' ') a 126 ('~').
** 1. c - 32     : Decale la plage [32, 126] vers [0, 94].
** 2. (unsigned) : Si c < 32, le resultat est negatif -> devient geant.
** 3. < 95       : On verifie si on est dans [0, 94].
*/
int	ft_isprint(int c)
{
	return ((unsigned int)(c - 32) < 95);
}
