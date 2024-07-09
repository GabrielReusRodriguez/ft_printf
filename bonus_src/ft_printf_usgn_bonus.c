/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/09 12:12:44 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

static	int	ft_format_precisition(unsigned int value, t_format format, char **str)
{
	(void)value;
	(void)str;
	if (format.n_precision > 0)
	{

	}
	return (0);
}

static	int	ft_format_width(unsigned int value, t_format format, char **str)
{	
	if (ft_format_padding(value, format, str) < 0)
		return (-1);
	if (ft_format_precisition(value, format, str) < 0)
		return (-1);
	return (0);
}

/*Sign flags + and space do not have sense with unsigned . When we compile it gives you a "warning"*/
int	ft_printf_usgn(int fd, va_list argp, t_format format)
{
	unsigned int	arg_value;
	char			*ch_number;
	int				num_bytes;

	(void)format;
	arg_value = va_arg(argp, unsigned int);
	ch_number = ft_utoa(arg_value);
	if (ch_number == NULL)
		return (-1);
	if (ft_format_width(arg_value, format, &ch_number) < 0)
		return (free (ch_number), -1);
	num_bytes = ft_iputstr_fd(ch_number, fd);
	free (ch_number);
	return (num_bytes);
}
