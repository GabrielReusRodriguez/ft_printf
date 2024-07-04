/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_up_hex_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:46 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 14:32:19 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_bonus.h"

char	*ft_printf_up_hex(va_list argp, t_format	*format)
{
	unsigned int	arg;
	char			*hex_number;

	arg = va_arg(argp, unsigned int);
	hex_number = ft_printf_htoa(arg, 1, format);
	return (hex_number);
}
