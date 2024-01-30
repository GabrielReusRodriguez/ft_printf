/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:13:27 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 20:31:49 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_printf_dec(va_list argp, t_format *format)
{
	if (format == NULL)
		return (NULL);
	return (ft_printf_int(argp, format));
}
