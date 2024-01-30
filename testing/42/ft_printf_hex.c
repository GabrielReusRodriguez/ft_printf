/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:52:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 17:01:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include <stdlib.h>

/*
Encargada de contar el numero de caracteres hexadecimales que usaremos para 
	representar el numero sin signo.
*/
/*
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
*/

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

static char	*ft_printf_htoa(unsigned int u_number, unsigned int up_case)
{
	size_t			num_digits;
	char			*str;
	unsigned int	digit;
	char			sr_digit;

	num_digits = ft_get_hex_digits(u_number);
	str = (char *)malloc(num_digits + 1);
	str[num_digits] = '\0';
	while (u_number / 16 != 0)
	{

		str[num_digits] = 
		u_number = u_number / 16;
	}
	return (str);
}

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

int	ft_printf_hex(unsigned int number, unsigned int up_case)
{
	return (ft_printf_hex_rec(number, up_case));
}
