/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:25:22 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 18:31:57 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Optimisation :
** On combine les deux logiques precedentes.
** 1. ((unsigned)(c - '0') < 10)        : Verifie si c'est un chiffre.
** 2. ((unsigned)((c | 32) - 'a') < 26) : Verifie si c'est une lettre.
**
** L'operateur || (OU logique) s'arrete des que la premiere condition est vraie
** (Short-circuit evaluation). Si c'est un chiffre, on ne teste meme
** pas la lettre.
*/

int	ft_isalnum(int c)
{
	return (((unsigned int)(c - '0') < 10)
		|| ((unsigned int)((c | 32) - 'a') < 26));
}
