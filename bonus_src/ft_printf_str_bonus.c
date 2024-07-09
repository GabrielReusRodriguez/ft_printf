/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/09 12:55:56 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with strings . When we compile it gives you a "warning"*/
/*The 0 flag does not apply to strings.*/

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
	format.b_zero = false;
	format.b_space = true;
	if (ft_format_padding(value, format, str) < 0)
		return (-1);
	if (ft_format_precisition(value, format, str) < 0)
		return (-1);
	return (0);
}

int	ft_printf_str(int fd, va_list argp, t_format format)
{
	char	*str;
	char	*arg;
	int		num_bytes;

	(void)format;
	arg = va_arg(argp, char *);
	if (arg != NULL)
		str = ft_strdup(arg);
	else
		str = ft_strdup("(null)");
	if (str == NULL)
		return (-1);
	if (ft_format_width(0,format, &str) <0)
		return (free (str), -1);
	num_bytes = ft_iputstr_fd(str, fd);
	free (str);
	return (num_bytes);
}
