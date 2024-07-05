/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:30 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/05 12:38:48 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#include "libft.h"
#include "ft_printf.h"

static int	ft_print_special_char(int fd, char c, va_list argp)
{
	if (c == 'c')
		return (ft_printf_char(fd, argp));
	if (c == 's')
		return (ft_printf_str(fd, argp));
	if (c == 'p')
		return (ft_printf_ptr(fd, argp));
	if (c == 'd')
		return (ft_printf_dec(fd, argp));
	if (c == 'i')
		return (ft_printf_int(fd, argp));
	if (c == 'u')
		return (ft_printf_usgn(fd, argp));
	if (c == 'x')
		return (ft_printf_low_hex(fd, argp));
	if (c == 'X')
		return (ft_printf_up_hex(fd, argp));
	if (c == '%')
		return (ft_printf_percent(fd));
	return (0);
}

int	ft_printf_fd(int fd, char const *str, ...)
{
	va_list	argp;
	int		num_bytes;
	size_t	i;

	num_bytes = 0;
	i = 0;
	va_start(argp, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], fd);
			num_bytes++;
		}
		else
		{
			num_bytes = num_bytes + ft_print_special_char(fd, str[i + 1], argp);
			i++;
		}
		i++;
	}
	va_end(argp);
	return (num_bytes);
}


int	ft_printf(char const *str, ...)
{
	va_list	argp;
	int		num_bytes;
	size_t	i;

	num_bytes = 0;
	i = 0;
	va_start(argp, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			num_bytes++;
		}
		else
		{
			num_bytes = num_bytes + ft_print_special_char(STDOUT_FILENO, str[i + 1], argp);
			i++;
		}
		i++;
	}
	va_end(argp);
	return (num_bytes);
}
