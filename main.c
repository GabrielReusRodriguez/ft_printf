#include "ft_printf.h"

int main(void)
{
    //ft_printf("Hola mundo!");
    int value;
    int ft_value;

    value = printf(" %p %p ", 0, 0);
    printf("\n");
    ft_value = ft_printf(" %p %p ", 0, 0);
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("_%-05%_");
    printf("\n");
    ft_value = ft_printf("_%-05%_");
    printf("value = %d vs ft_value %d \n",value, ft_value);
    return (0);
}