/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:16:29 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 18:30:09 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Optimisation Bitwise :
** 1. (c | 32) : converti en min.
** 2. - 'a'    : soustraire a a-a = 0.
** 3. (unsigned): si neg le cast transforme en + de 26
** 4. < 26     : check si entre 0 et 25 (lettre)
*/
int	isalpha(int c)
{
	return (((unsigned int)(c | 32) - 'a') < 26);
}
