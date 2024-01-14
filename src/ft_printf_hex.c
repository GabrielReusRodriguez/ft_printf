/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:52:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/14 01:51:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include <stdio.h>

/*
Encargada de contar el numero de caracteres hexadecimales que usaremos para 
	representar el numero sin signo.
*/
static int	ft_count_hex_chars(unsigned int num)
{
	int	num_chars;

	num_chars = 1;
	while (num / 16 != 0)
	{
		num = num /16;
		num_chars++;
	}
	return (num_chars);
}

static void ft_printf_hex_rec(unsigned int u_number, unsigned int up_case)
{
	char	start_digit;

	if (u_number < 10)
	{
		start_digit = '0';
		ft_putchar_fd(start_digit + u_number, 1);
		return ;
	}
	if(u_number < 16)
	{
		if (up_case == 1)
			start_digit = 'A';
		else
			start_digit = 'a';
		ft_putchar_fd(start_digit + (u_number - 10), 1);
		return ;
	}
	ft_printf_hex_rec(u_number / 16, up_case);
	ft_printf_hex_rec(u_number % 16, up_case);
}

int	ft_printf_hex(unsigned int number, unsigned int up_case)
{
	
	int				num_bytes;

	num_bytes = ft_count_hex_chars(number);
	ft_printf_hex_rec(number, up_case);
	return (num_bytes);
	
}

/*
int	ft_printf_hex(int arg, unsigned int up_case)
{
	
	int				num_bytes;
	unsigned int	u_number;

	num_bytes = 0;
	if (arg < 0)
	{	num_bytes++;
		u_number = arg * (-1);
		ft_putchar_fd('-',1);
	}
	else
		u_number = arg;
	num_bytes = num_bytes + ft_count_hex_chars(u_number);
	ft_printf_hex_rec(u_number, up_case);
	return (num_bytes);
	
}
*/