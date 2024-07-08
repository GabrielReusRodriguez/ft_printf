/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/08 23:47:51 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

static int	ft_format_padding(unsigned int value, t_format format, char **str)
{
	char	*padding;
	char	*formated_str;

	(void)value;
	printf("WIDTH:: %ld\n", format.n_width);
	if (format.n_width > 0)
	{
		padding = malloc(format.n_width + 1);
		if (padding == NULL)
			return (-1);
		ft_memset(padding, '0', format.n_width);
		formated_str = ft_strjoin(padding, *str);
		if (formated_str == NULL)
			return (free(padding), -1);
		free (*str);
		free (padding);
		*str = formated_str;
	}
	return (0);
}

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
