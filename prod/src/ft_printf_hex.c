/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:52:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/30 00:31:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"


static char	ft_printf_get_hex_char(unsigned long long u_number, unsigned int up_case)
{
	char	hex_digit;

	hex_digit = ' ';
	if (u_number < 10)
	{
		hex_digit = '0' + u_number;
		return (hex_digit);
	}
	if(u_number < 16)
	{
		if (up_case == 1)
			hex_digit = 'A' + (u_number - 10);
		else
			hex_digit = 'a' + (u_number - 10);
	}
	return (hex_digit);
}

static size_t	ft_get_hex_digits(unsigned long long u_number)
{
	size_t	num_digits;

	num_digits = 1;
	while (u_number / 16 != 0)
	{
		u_number = u_number / 16;
		num_digits++;
	}
	return (num_digits);
}

#include <stdio.h>
char	*ft_printf_htoa(unsigned long long u_number, unsigned int up_case,  t_format	*format)
{
	size_t			num_digits;
	char			*str;

	(void)format;
	num_digits = ft_get_hex_digits(u_number);
	//printf("Num digitos %lu\n", num_digits);
	str = (char *)malloc(num_digits + 1);
	str[num_digits] = '\0';
	//num_digits--;
	//while (u_number / 16 != 0)
	while (num_digits > 0)
	{
		//printf("\t\tnumero digit : %lu \n",num_digits);
		str[num_digits - 1] = ft_printf_get_hex_char(u_number % 16, up_case);
		u_number = u_number / 16;
		num_digits--;
	}
	return (str);
}
