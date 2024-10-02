#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_print_percent(void);
void ft_print_pointer(void *ptr);
void ft_print_hex_lower(unsigned int n);
void ft_print_hex_upper(unsigned int n);
void ft_print_unsigned(unsigned int n);
void ft_print_integer(int n);
void ft_print_string(char *str);
void ft_print_char(char c);
int ft_printf(const char *format, ...);
void ft_parse_format(const char *format, va_list args);
int ft_handle_specifier(const char *format, va_list args);