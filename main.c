#include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    //ft_printf("Hola mundo!");
    int value;
    int ft_value;

    /*Int tests*/
    /*
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
*/
    //Width
    /*
    value = printf("ua %5u %5u \n", 0, 1);
    //value = 1;
    ft_value = ft_printf("ub %5u %5u \n", 0, 1);
    //ft_value = ft_printf("au %5u \n", 0);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    */
    /*
    printf("%5c\n",'r');
    printf("%05c\n",'a');
    printf("%7X\n", 33);
    printf("%3X\n",0);
    printf("%5X\n", 52625);
    printf("a%s\n", NULL);
    ft_printf("b%s\n", NULL);
    */
   /*
    value = printf("a%23s\n", NULL);
    fflush(stdout); 
    ft_value = ft_printf("b%23s\n", NULL);
    fflush(stdout); 
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout); 
    
    value = printf("a%16s\n", "nark nark");
    fflush(stdout);
    ft_value = ft_printf("b%16s\n", "nark nark");
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
    value = printf("a%5s\n", "goes over");
    fflush(stdout);
    ft_value = ft_printf("b%5s\n", "goes over");
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
    value = printf("a%2s\n", NULL);
    fflush(stdout);
    ft_value = ft_printf("b%2s\n", NULL);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);

    */

    //Precision  *******************************************
/*
    value = printf("_%.u_\n", 1000);
    fflush(stdout);
    ft_value = ft_printf("_%.u_\n", 1000);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);

    value = printf("%.10u\n", 2000);
    fflush(stdout);
    ft_value = printf("%.10u\n", 2000);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);

    value = printf("%-.10u\n", 3000);
    fflush(stdout);
    ft_value = ft_printf("%-.10u\n", 3000);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);

    value = printf("%20u\n", 4000);
    fflush(stdout);
    ft_value = ft_printf("%20u\n", 4000);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);

    value = printf("%20.10u\n", 5000);
    fflush(stdout);
    ft_value = ft_printf("%20.10u\n", 5000);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
*/
/*
    printf("%+.d\n", 1000);
    printf("%+.10d\n", 1000);
    printf("%-.10d\n", 1000);
    printf("%.10d\n", -1000);
    printf("%-.10d\n", -1000);
    printf("%20d\n", 1000);
    printf("%20.10d\n", 1000);
*/
/*
    value = printf("_%.s_\n", NULL);
    fflush(stdout);
    ft_value = ft_printf("_%.s_\n", NULL);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);

    value = printf("_%.s_\n", NULL);
    fflush(stdout);
    ft_value = ft_printf("_%.s_\n", NULL);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
*/  
/*
    value = printf("%.6i\n", -3);
    fflush(stdout);
    ft_value = ft_printf("%.6i\n", -3);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
    */
   /*
    value = printf("%08.3i\n", 8375);
    fflush(stdout);
    ft_value = ft_printf("%08.3i\n", 8375);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
    */
/*
    value = printf("%7.4i\n", -14);
    fflush(stdout);
    ft_value = ft_printf("%7.4i\n", -14);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);

    value = printf("%07d\n", -54);
    fflush(stdout);
    ft_value = ft_printf("%07d\n", -54);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
  */  

    value = printf("%7.5s\n", "bombastic");
    fflush(stdout);
    ft_value = ft_printf("%7.5s\n", "bombastic");
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);

/*
    value = printf("%i\n", -54);
    fflush(stdout);
    ft_value = ft_printf("%i\n", -54);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
*/
/*
    value = printf("_%.1d_\n", 51);
    fflush(stdout);
    ft_value = ft_printf("_%.1d_\n", 51);
    fflush(stdout);
    printf("value = %d vs ft_value %d \n",value, ft_value);
    fflush(stdout);
*/

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