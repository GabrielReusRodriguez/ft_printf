/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:52:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/06 00:58:35 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include "libft.h"
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with hex . When we compile it gives you a "warning"*/

static int	ft_format_hashtag(int fd, bool up_case, t_format format)
{
	if (format.b_hash)
	{
		if (up_case)
			return (ft_iputstr_fd("0X", fd));
		return (ft_iputstr_fd("0x", fd));
	}
	return (0);
}

static int	ft_number_2_hex(int fd, unsigned long u_number, bool up_case, \
				t_format format)
{
	char	start_digit;
	int		num_bytes;
	int		return_value;

	num_bytes = 0;
	if (u_number < 10)
		return (ft_iputchar_fd('0' + u_number, fd));
	if (u_number < 16)
	{
		if (up_case == true)
			start_digit = 'A';
		else
			start_digit = 'a';
		return (ft_iputchar_fd(start_digit + (u_number - 10), fd));
	}
	return_value = ft_number_2_hex(fd, u_number / 16, up_case, format);
	if (return_value < 0)
		return (-1);
	num_bytes = num_bytes + return_value;
	return_value = ft_number_2_hex(fd, u_number % 16, up_case, format);
	if (return_value < 0)
		return (-1);
	num_bytes = num_bytes + return_value;
	return (num_bytes);
}

int	ft_printf_hex(int fd, unsigned long number, bool up_case, t_format format)
{
	int	total_num_bytes;
	int	num_bytes;

	total_num_bytes = 0;
	num_bytes = ft_format_hashtag(fd, up_case, format);
	if (num_bytes < 0)
		return (-1);
	total_num_bytes += num_bytes;	
	num_bytes += ft_number_2_hex(fd, number, up_case, format);
	if (num_bytes < 0)
		return (-1);
	total_num_bytes += num_bytes;	
	return (total_num_bytes);
}
