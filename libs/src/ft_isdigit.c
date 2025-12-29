/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:25:18 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 18:31:21 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Optimisation :
** 1. c - '0'    : Decale la valeur ASCII. '0' devient 0, '9' devient 9.
** 2. (unsigned) : Si c < '0', le resultat est negatif, le cast le rend geant.
**                 Si c > '9', le resultat est > 9.
** 3. < 10       : On verifie simplement si le resultat est dans [0, 9].
*/

int	ft_isdigit(int c)
{
	return ((unsigned int)(c - '0') < 10); 
}
