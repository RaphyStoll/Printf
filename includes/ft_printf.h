#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "type.h"

/*
** Prototype principal
*/
int		ft_printf(const char *format, ...);

/*
** Init & Parsing
*/
t_print	*ft_initialise_tab(t_print *tab);
int		ft_eval_format(t_print *tab, const char *format, int pos);

/*
** Utils (A remplacer par ta Libft si tu l'as)
*/
int		ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_putchar(char c);

#endif
