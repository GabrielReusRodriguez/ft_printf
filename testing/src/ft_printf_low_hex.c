/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_low_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 20:02:28 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/* Le paso un numero int y lo convierte a hex*/
char	*ft_printf_low_hex(va_list argp, t_format *format)
{
	unsigned int	arg;
	char			*str;

	arg = va_arg(argp, unsigned int);
	str = ft_printf_htoa(arg, 0);
	return (str);
}
