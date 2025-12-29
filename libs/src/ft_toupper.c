/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:36:00 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 18:57:29 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/*
** Optimisation (Branchless) :
** On utilise le resultat de la comparaison (0 ou 1) pour eviter un if.
** Si c est une minuscule (a-z), on soustrait 32.
** Sinon, on soustrait 0.
*/
int	ft_toupper(int c)
{
	return (c - 32 * ((unsigned int)(c - 'a') < 26));
}
