#ifndef TYPE_H
# define TYPE_H

# include <stdarg.h>

/*
** Structure pour gérer les flags et l'état de l'impression
** wdt  : width (largeur min)
** prc  : precision
** zero : flag '0' (padding avec des zéros)
** pnt  : flag '.' (précision activée)
** dash : flag '-' (alignement à gauche)
** tl   : total length (valeur de retour finale)
** sign : flag '+' (force l'affichage du signe)
** sp   : flag ' ' (espace si positif)
** hash : flag '#' (préfixe 0x ou 0)
*/

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		sp;
	int		hash;
}	t_print;

#endif
