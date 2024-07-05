/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_up_hex_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:46 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/06 00:47:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with low hex . When we compile it gives you a "warning"*/
/*Hashtag flag is treated at ft_print_hex*/
int	ft_printf_up_hex(int fd, va_list argp, t_format format)
{
	int				num_bytes;
	unsigned int	arg;

	arg = va_arg(argp, unsigned int);
	num_bytes = ft_printf_hex(fd, arg, arg, format);
	return (num_bytes);
}
