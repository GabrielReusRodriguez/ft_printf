/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:25:44 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/24 00:08:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../src/ft_printf.h"
#include <limits.h>

int main(void)
{
    int ft_num_bytes;
    int num_bytes;

    printf("TEST Vanilla\n");
    ft_num_bytes = ft_printf("\tHola mundo!\n");
    num_bytes = printf("\tHola mundo!\n");
    printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
/*
    printf("TEST Chars\n");
    ft_num_bytes = ft_printf("\tHola mundo %c!\n",'t');
    num_bytes = printf("\tHola mundo %c!\n",'t');
    printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);

    printf("TEST Strings\n");
    ft_num_bytes = ft_printf("\tHola mundo %s!\n","Gabriel");
    num_bytes = printf("\tHola mundo %s!\n","Gabriel");
    printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    
    printf("TEST %%\n");
    ft_num_bytes = ft_printf("\tHola mundo %%!\n");
    num_bytes = printf("\tHola mundo %%!\n");
    printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);

    printf("TEST i\n");
    int nums[] = {INT_MIN, -40, -03, 0, 00, 01, 1, 160, 045, INT_MAX};
    for(int i = 0;i <10; i++)
    {
        ft_num_bytes = ft_printf("\tHola mundo %i!\n",nums[i]);
        num_bytes = printf("\tHola mundo %i!\n", nums[i]);
        printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    }
    
    printf("TEST d\n");
    //int nums[] = {INT_MIN, -40, -03, 0, 00, 01, 1, 160, 045, INT_MAX};
    for(int i = 0;i <10; i++)
    {
        ft_num_bytes = ft_printf("\tHola mundo %d!\n",nums[i]);
        num_bytes = printf("\tHola mundo %d!\n", nums[i]);
        printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    }

    printf("TEST u\n");
    //int nums[] = {INT_MIN, -40, -03, 0, 00, 01, 1, 160, 045, INT_MAX};
    for(int i = 0;i <10; i++)
    {
        ft_num_bytes = ft_printf("\tHola mundo %u!\n",nums[i]);
        num_bytes = printf("\tHola mundo %u!\n", nums[i]);
        printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    }
    ft_num_bytes = ft_printf("\tHola mundo %u!\n",UINT_MAX);
    num_bytes = printf("\tHola mundo %u!\n", UINT_MAX);
    printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);

    printf("TEST x\n");
    unsigned int to_hex[] = {INT_MIN, -40, -03, 0, 00, 01, 1, 160, 045, INT_MAX, UINT_MAX};
    printf("\tnums....\n");
    for(int i = 0;i <10; i++)
    {
        
        num_bytes = printf("\tHola mundo %x!\n", nums[i]);
        ft_num_bytes = ft_printf("\tHola mundo %x!\n",nums[i]);
        printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    }
    printf("\tunsigned....\n");
    for(int i = 0;i <11; i++)
    {
        
        num_bytes = printf("\tHola mundo %x!\n", to_hex[i]);
        ft_num_bytes = ft_printf("\tHola mundo %x!\n",to_hex[i]);
        printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    }

    printf("TEST X\n");
    printf("\tnums....\n");
    for(int i = 0;i <10; i++)
    {
        
        num_bytes = printf("\tHola mundo %X!\n", nums[i]);
        ft_num_bytes = ft_printf("\tHola mundo %X!\n",nums[i]);
        printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    }
    printf("\tunsigned....\n");
    for(int i = 0;i <11; i++)
    {
        
        num_bytes = printf("\tHola mundo %X!\n", to_hex[i]);
        ft_num_bytes = ft_printf("\tHola mundo %X!\n",to_hex[i]);
        printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    }

    printf("TEST P\n");
    num_bytes = printf("\tHola mundo _%p_!\n",to_hex);
    ft_num_bytes = ft_printf("\tHola mundo _%p_!\n",to_hex);
    printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    num_bytes = printf("\tHola mundo _%p_!\n",NULL);
    ft_num_bytes = ft_printf("\tHola mundo _%p_!\n",NULL);
    printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);
    num_bytes = printf("\tHola mundo _%p_\n",to_hex + 1);
    ft_num_bytes = ft_printf("\tHola mundo _%p_\n",to_hex + 1);
    printf("\t\tNum bytes = %d vs ft num bytes = %d\n",num_bytes, ft_num_bytes);

*/
    return(0);
}