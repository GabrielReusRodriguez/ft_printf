/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_low_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/14 22:48:18 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/* Le paso un numero int y lo convierte a hex*/
int	ft_printf_low_hex(va_list argp)
{
	int				num_bytes;
	unsigned int	arg;
	
	num_bytes = 0;
	arg = va_arg(argp, unsigned int);
	num_bytes = ft_printf_hex(arg, 0);
	return (num_bytes);
}
