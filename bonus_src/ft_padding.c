/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:40:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 18:04:32 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf_bonus.h"

/*
Be carefull! a - overwrites the 0 flag (man says it)
If it is a pointer and we fill it with 0s, we substract 2 because 
all pointers start with 0x.
If we have to write spaces then we should write them afer /before
0xhex
*/

void    ft_determine_padding(size_t *size, char *chr_padding, t_format *format)
{
    if (format->b_zero == 1 && format->b_minus == 0)
     {
         chr_padding = '0';
     }
     else
         chr_padding = ' ';
     if (format->c_data_type == 'p' && format->b_zero == 1)
         size = size - 2;
}


char	*ft_create_padding(size_t size, char chr_padding)
{
	char	*aux;
	char	*padding;

	padding = ft_calloc(size + 1, 1);
	if (padding == NULL)
		return (NULL);
	aux = padding;
	padding = ft_memset(padding, chr_padding, size);
	if (padding == NULL)
	{
		free(aux);
		return (NULL);
	}
	return (padding);
}

/*

static char *ft_create_padding(size_t size, t_format *format)
{   
     char    *aux;
     char    *padding;
     char    chr_padding;
     
     if (format->b_zero == 1 && format->b_minus == 0)
     {
         chr_padding = '0';
     }
     else
         chr_padding = ' ';
     if (format->c_data_type == 'p' && format->b_zero == 1)
         size = size - 2;
     padding = ft_calloc(size + 1, 1);
     if (padding == NULL)
         return (NULL);
     aux = padding;
     padding = ft_memset(padding, chr_padding, size);
     if (padding == NULL)
     {
         free(aux);
         return (NULL);
     }
     return (padding);
 }  
*/

