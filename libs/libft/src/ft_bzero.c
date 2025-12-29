/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:41:00 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 19:21:17 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Implementation standard de bzero.
** Utilise ft_memset pour mettre a zero.
** Deprecie par la norme POSIX
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
