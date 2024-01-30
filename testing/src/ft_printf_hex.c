/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:52:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 20:12:19 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_get_hex_digits(unsigned int u_number)
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

static char	ft_printf_get_hex_digit(unsigned int u_number, unsigned int up_case)
{
	char	hex_digit;

	hex_digit = ' ';
	if (u_number < 10)
	{
		hex_digit = '0' + u_number;
	}
	else
	{
		if (up_case == 1)
			hex_digit = 'A' + (u_number - 10);
		else
			hex_digit = 'a' + (u_number - 10);
	}
	return (hex_digit);
}

char	*ft_printf_htoa(unsigned long long u_number, unsigned int up_case)
{
	size_t			num_digits;
	char			*str;
	unsigned int	digit;
	char			str_digit;

	num_digits = ft_get_hex_digits(u_number);
	str = (char *)malloc(num_digits + 1);
	if (str == NULL)
		return (NULL);
	str[num_digits] = '\0';
	//while (u_number / 16 != 0)
	while (num_digits > 0)
	{

		str[num_digits - 1] = ft_printf_get_hex_digit(u_number % 16,up_case);
		u_number = u_number / 16;
		num_digits --;
	}
	return (str);
}

/*
static int	ft_printf_hex_rec(unsigned int u_number, unsigned int up_case)
{
	char	start_digit;
	int		num_bytes;

	num_bytes = 0;
	if (u_number < 10)
	{
		start_digit = '0';
		return (ft_iputchar_fd(start_digit + u_number, 1));
	}
	if (u_number < 16)
	{
		if (up_case == 1)
			start_digit = 'A';
		else
			start_digit = 'a';
		return (ft_iputchar_fd(start_digit + (u_number - 10), 1));
	}
	num_bytes = num_bytes + ft_printf_hex_rec(u_number / 16, up_case);
	num_bytes = num_bytes + ft_printf_hex_rec(u_number % 16, up_case);
	return (num_bytes);
}

int	ft_printf_hex(unsigned int number, unsigned int up_case, t_format *format)
{
	(void)format;
	return (ft_printf_hex_rec(number, up_case));
}


#include <stdio.h>

int main(void)
{
	printf("VALOR: _%s_\n", ft_printf_htoa( 32 , 1));
}
*/