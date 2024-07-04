/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_up_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:46 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/04 22:13:56 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf_up_hex(va_list argp)
{
	int				num_bytes;
	unsigned int	arg;

	arg = va_arg(argp, unsigned int);
	num_bytes = ft_printf_hex(arg, 1);
	return (num_bytes);
}
