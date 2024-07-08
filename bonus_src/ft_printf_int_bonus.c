/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:14:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/08 23:34:45 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

static int	ft_format_plus(int value, t_format format, char **num)
{
	char	*formated_str;
	
	if (format.b_plus)
	{
		if (value >= 0)
		{
			formated_str = ft_strjoin("+", *num);
			if (formated_str == NULL)
				return (-1);
			free (*num);
			*num = formated_str;
		}
	}
	return (0);
}

static int	ft_format_space(int value, t_format format, char **num)
{
	char	*formated_str;
	
	if (format.b_space && !format.b_plus)
	{
		if (value >= 0)
		{
			formated_str = ft_strjoin(" ", *num);
			if (formated_str == NULL)
				return (-1);
			free (*num);
			*num = formated_str;
		}
	}
	return (0);
}

static int	ft_format_prefix(int value, t_format format, char **num)
{
	if (ft_format_plus(value, format, num) < 0)
		return (-1);
	if (ft_format_space(value, format, num) < 0)
		return (-1);
	return (0);
}

//First we treat the sign flags.
int	ft_printf_int(int fd, va_list argp, t_format format)
{
	int		num_bytes;
	int		arg_value;
	char	*num;

	arg_value = va_arg(argp, int);
	num = ft_itoa(arg_value);
	if (num != NULL)
	{
		if (ft_format_prefix(arg_value, format, &num) ==  -1)
			return (free (num), -1);
		num_bytes = ft_iputstr_fd(num, fd);
		free (num);
		return (num_bytes);
	}
	else
		return (-1);
}
