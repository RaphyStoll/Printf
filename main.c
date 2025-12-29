#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	check(char *desc, int ret_ft, int ret_orig);

int main()
{
    int ret1, ret2;

    printf("\n=== 1. BASIC TESTS ===\n");
    ft_printf("Moi: %c %s %p %d %i %u %x %X %%\n", 'A', "Test", (void *)1, 42, -42, 42, 42, 42);
    printf("Lui: %c %s %p %d %i %u %x %X %%\n", 'A', "Test", (void *)1, 42, -42, 42, 42, 42);

    printf("\n=== 2. WIDTH (Largeur) ===\n");
    ret1 = ft_printf("|%5d| |%-5d| |%5s|\n", 42, 42, "Hi");
    ret2 = printf("|%5d| |%-5d| |%5s|\n", 42, 42, "Hi");
    check("Width", ret1, ret2);

    printf("\n=== 3. PRECISION (.) ===\n");
    ret1 = ft_printf("|%.5d| |%.2s| |%.d|\n", 42, "Hello", 0);
    ret2 = printf("|%.5d| |%.2s| |%.d|\n", 42, "Hello", 0);
    check("Precision", ret1, ret2);

    printf("\n=== 4. ZERO FLAG (0) ===\n");
    ret1 = ft_printf("|%05d| |%05x|\n", 42, 42);
    ret2 = printf("|%05d| |%05x|\n", 42, 42);
    check("Zero Flag", ret1, ret2);

    printf("\n=== 5. COMPLEX FLAGS (# + space) ===\n");
    ret1 = ft_printf("|%#x| |%+d| |% d|\n", 42, 42, 42);
    ret2 = printf("|%#x| |%+d| |% d|\n", 42, 42, 42);
    check("Hash/Plus/Space", ret1, ret2);

    printf("\n=== 6. THE TRICKY ONES (Combos) ===\n");
    // 0 flag est ignoré si precision est presente pour les int
    printf("Test: %%05.3d (0 doit etre ignore)\n");
    ret1 = ft_printf("|%05.3d|\n", 42);
    ret2 = printf("|%05.3d|\n", 42);
    check("0 flag vs Precision", ret1, ret2);

    printf("Test: %%#010x (Hash + 0 + Width)\n");
    ret1 = ft_printf("|%#010x|\n", 42);
    ret2 = printf("|%#010x|\n", 42);
    check("Hash + 0 + Width", ret1, ret2);

    printf("Test: %%+5d (Plus + Width)\n");
    ret1 = ft_printf("|%+5d|\n", 42);
    ret2 = printf("|%+5d|\n", 42);
    check("Plus + Width", ret1, ret2);

    return 0;
}

static void	check(char *desc, int ret_ft, int ret_orig)
{
    if (ret_ft == ret_orig)
        printf("✅ [%s] Returns match : %d\n", desc, ret_ft);
    else
        printf("❌ [%s] Returns DIFF : FT=%d / ORIG=%d\n", desc, ret_ft, ret_orig);
    printf("--------------------------------\n");
}