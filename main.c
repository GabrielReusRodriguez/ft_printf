#include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    //ft_printf("Hola mundo!");
    int value;
    int ft_value;

    /*Int tests*/
    printf("PLUS **********************\n");
    value = printf(" %+d %d ", 5, 5);
    printf("\n");
    ft_value = ft_printf(" %+d %d ", 5, 5);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf(" %+d %d ", -5, -5);
    printf("\n");
    ft_value = ft_printf(" %+d %d ", -5, -5);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf(" %+d %d ", 0, 0);
    printf("\n");
    ft_value = ft_printf(" %+d %d ", 0, 0);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("u %+u %u ", 5, 5);
    printf("\n");
    ft_value = ft_printf("u %+u %u ", 5, 5);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("u %+u %u ", -5, -5);
    printf("\n");
    ft_value = ft_printf("u %+u %u ", -5, -5);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("u %+u %u ", 0, 0);
    printf("\n");
    ft_value = ft_printf("u %+u %u ", 0, 0);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    //SPACE
    printf("SPACE **********************\n");
    value = printf(" % d %d ", 0, 0);
    printf("\n");
    ft_value = ft_printf(" % d %d ", 0, 0);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);


    value = printf(" % d %d ", 5, 5);
    printf("\n");
    ft_value = ft_printf(" % d %d ", 5, 5);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf(" % d %d ", -5, -5);
    printf("\n");
    ft_value = ft_printf(" % d %d ", -5, -5);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);


    value = printf("u % u %u ", -5, -5);
    printf("\n");
    ft_value = ft_printf("u % u %u ", -5, -5);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("u % u %u ", 0, 0);
    printf("\n");
    ft_value = ft_printf("u % u %u ", 0, 0);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("s % s %s ", "hola", "hola");
    printf("\n");
    ft_value = ft_printf("s % s %s ", "hola", "hola");
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("s %+s %s ", "hola", "hola");
    printf("\n");
    ft_value = ft_printf("s %+s %s ", "hola", "hola");
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("p % p %p ", NULL, NULL);
    printf("\n");
    ft_value = ft_printf("p % p %p ", NULL, NULL);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    value = printf("p %+p %p ", NULL, NULL);
    printf("\n");
    ft_value = ft_printf("p %+p %p ", NULL, NULL);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);


    value = printf("p %p %p ", &value, &ft_value);
    printf("\n");
    ft_value = ft_printf("p %p %p ", &value, &ft_value);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    //Width
    
    value = printf("u %5u %5u ", 0, 0);
    printf("\n");
    ft_value = ft_printf("u %5u %5u ", 0, 0);
    printf("\n");
    printf("value = %d vs ft_value %d \n",value, ft_value);

    /*PTRS test*/
/*
    value = printf(" %p %p ", NULL, NULL);
    printf("\n");
    ft_value = ft_printf(" %p %p ", NULL, NULL);
    printf("value = %d vs ft_value %d \n",value, ft_value);
*/
/*
    value = printf("_%-05%_");
    printf("\n");
    ft_value = ft_printf("_%-05%_");
    printf("value = %d vs ft_value %d \n",value, ft_value);
 */
    return (0);
}