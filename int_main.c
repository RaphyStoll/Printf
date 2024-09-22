#include <stdio.h>
#include "ft_printf.h"
int main()
{
	int a = 1;
	char b = 'a';
	char *c = "hello World!";
	//printf("int a = %d\nchar b = %c\nchar *c = %s\n", a, b, c);
	ft_printf("int a = %d\n", a); 
	//ft_printf("char b =%c\n", b);
	//ft_printf("char *c = %s\n", c);
}