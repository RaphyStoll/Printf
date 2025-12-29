/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:09:00 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 19:27:14 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Ecrit le caractere c sur le descripteur de fichier fd.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
