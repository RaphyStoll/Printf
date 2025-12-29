/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:34:41 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 21:55:02 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Cette fonction sert a reinitialiser les flags avant de parser un nouveau %.
** On ne touche PAS a tab->args ni a tab->tl ici.
*/
t_print	*initialise_tab(t_print *tab)
{
    tab->wdt = 0;
    tab->prc = 0;
    tab->zero = 0;
    tab->pnt = 0;
    tab->dash = 0;
    tab->sign = 0;
    tab->zero = 0;
    tab->sp = 0;
    tab->hash = 0;
    return (tab);
}