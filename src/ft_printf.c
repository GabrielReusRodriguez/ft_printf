/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:30 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/14 01:31:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "../libft/libft.h"
#include "ft_printf.h"

static int ft_print_special_char(char c, va_list argp)
{
	if (c == 'c')
		return (ft_printf_char(argp));
	if (c == 's')
		return (ft_printf_str(argp));
	if (c == 'p')
		return (ft_printf_ptr(argp));
	if (c == 'd')
		return (ft_printf_dec(argp));
	if (c == 'i')
		return (ft_printf_int(argp));
	if (c == 'u')
		return (ft_printf_usgn(argp));
	if (c == 'x')
		return (ft_printf_low_hex(argp));		
	if (c == 'X')
		return (ft_printf_up_hex(argp));		
	if (c == '%')
		return (ft_printf_percent());
	return (0);
}

int ft_printf(char const *str, ...)
{
	va_list argp;
	int     num_bytes;
	size_t  i;
	
	num_bytes = 0;
	i = 0;
	va_start(argp, str);
	while(str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i],1);
			num_bytes++;
		}
		else
		{
			num_bytes = num_bytes + ft_print_special_char(str[i + 1], argp);
			i++;
		}
		i++;
	}
	va_end(argp);
	return (num_bytes);
}