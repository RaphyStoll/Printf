/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:27:09 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 18:51:02 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Optimisation :
** ASCII est defini sur 7 bits (0-127).
** 1. (unsigned) : Si c est negatif, il devient une valeur enorme.
** 2. < 128      : On verifie si c est dans la plage [0, 127].
**
** Une seule comparaison, pas de branchement logique.
*/
int	ft_isascii(int c)
{
    return ((unsigned int)c < 128);
}
