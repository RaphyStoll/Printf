/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:40:00 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 18:58:29 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/*
** Implementation standard de memset.
** Remplit une zone memoire avec un octet donne.
** Retourne le pointeur d'origine.
*/
void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (s);
}
