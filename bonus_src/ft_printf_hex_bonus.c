/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:52:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/05 12:35:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include "libft.h"

static int	ft_number_2_hex(int fd, unsigned long u_number, bool up_case)
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
	return_value = ft_number_2_hex(fd, u_number / 16, up_case);
	if (return_value < 0)
		return (-1);
	num_bytes = num_bytes + return_value;
	return_value = ft_number_2_hex(fd, u_number % 16, up_case);
	if (return_value < 0)
		return (-1);
	num_bytes = num_bytes + return_value;
	return (num_bytes);
}

int	ft_printf_hex(int fd, unsigned long number, bool up_case)
{
	return (ft_number_2_hex(fd, number, up_case));
}
