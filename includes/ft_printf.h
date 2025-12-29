#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "types.h"
# include "types_trash.h"
# include "../libs/libft/includes/libft.h"

int		ft_printf(const char *format, ...);
t_print	*initialise_tab(t_print *tab);
int		eval_format(t_print *tab, const char *format, int pos);
void	print_char(t_print *tab);
void	print_str(t_print *tab);
void	print_ptr(t_print *tab);
void	print_nbr(t_print *tab);
void	print_unsigned(t_print *tab);
void	print_hex(t_print *tab, const char type);
void	print_percent(t_print *tab);

#endif
