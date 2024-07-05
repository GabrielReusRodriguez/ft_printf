/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:14:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/06 00:33:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

static int	ft_format_plus(int fd, int value, t_format format)
{
	if (format.b_plus)
	{
		if (value >= 0)
			return (ft_iputchar_fd('+', fd));
	}
	return (0);

}

static int	ft_format_space(int fd, int value, t_format format)
{
	if (format.b_space && !format.b_plus)
	{
		if (value >= 0)
			return (ft_iputchar_fd(' ', fd));
	}
	return (0);

}

//First we treat the sign flags.
int	ft_printf_int(int fd, va_list argp, t_format format)
{
	int		num_bytes;
	int		arg_value;
	char	*num;

	num_bytes = 0;
	arg_value = va_arg(argp, int);
	num = ft_itoa(arg_value);
	if (num != NULL)
	{
		num_bytes+= ft_format_plus(fd, arg_value, format);
		num_bytes+= ft_format_space(fd, arg_value, format);
		num_bytes+= ft_iputstr_fd(num, fd);
		free (num);
		return (num_bytes);
	}
	else
		return (-1);
}
