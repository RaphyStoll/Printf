
#include "ft_printf.h"
int main()
{
	char a = 'a';
	char *b = "Hello World!";
	int c = 42;
	unsigned int d = 4294967268;
	int e = 255;
	int *f = 0;
	
	//? pas implementer
	printf("sans flag - : %5d\n", c);
	printf("avec flag - : %-5d\n", c);
	puts("\n");
	
	//? merci gpt
	ft_printf("string sans selecteur 42\n");
	ft_printf("chaine vide : %s\n", NULL);
	ft_printf("Grand chiffre : %d\n", -2147483648);
	ft_printf("Pointeur null : %p\n", NULL);
	printf("Printf pointeur null : %p\n", NULL);
	puts("\n");

	//? mes test
	ft_printf("Caractère : %c\n", a);
    ft_printf("Chaîne : %s\n", b);
    ft_printf("Entier d: %d\n", c);
	ft_printf("Entier i: %i\n", c);
    ft_printf("Unsigned : %u\n", d);
    ft_printf("Hexadecimal (minuscule) : %x\n", e);
    ft_printf("Hexadecimal (majuscule) : %X\n", e);
	printf("printf Pointeur : %p\n",f);
    ft_printf("ft_printf Pointeur : %p\n", f);
    ft_printf("Pourcentage : %%\n");
    return 0;
}