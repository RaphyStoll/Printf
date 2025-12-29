/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:37:00 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 18:57:44 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/*
** Optimisation (Branchless) :
** Meme logique que toupper.
** Si c est une majuscule (A-Z), on ajoute 32.
*/
int	ft_tolower(int c)
{
	return (c + 32 * ((unsigned int)(c - 'A') < 26));
}
