/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:14:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/11 23:35:47 by gabriel          ###   ########.fr       */
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

/* If  value is < 0 we ALWAYS show the minus.
if not, it depends of flags*/
static int	ft_format_prefix(int value, t_format format, char **num)
{
	char	*formated_num;
	
	if (value < 0)
	{
		formated_num = ft_strjoin("-", *num);
		if (formated_num == NULL)
			return (-1);
		free (*num);
		*num = formated_num;
	}
	else
	{
		if (ft_format_plus(value, format, num) < 0)
			return (-1);
		if (ft_format_space(value, format, num) < 0)
			return (-1);
	}
	return (0);
}

#include <stdio.h>
/*
	We have to look, if the padding is with 0s  we have to put de zeros and then 
	the minus signus in front.
	if there are spaces
	we put the number, the sign and then spaces at padding
*/
int	ft_printf_int(int fd, va_list argp, t_format format)
{
	int					num_bytes;
	int					arg_value;
	char				*num;
//	int		pos_num;
	unsigned int		pos_num;


	arg_value = va_arg(argp, int);
	if (arg_value < 0)
		pos_num = arg_value * (-1);
	else
		pos_num = arg_value;
	num = ft_utoa(pos_num);
//	num = ft_itoa(pos_num);
	if (num != NULL)
	{
		if (format.b_dot)
		{
			format.b_zero = false;
			if (ft_format_precision(format, &num) < 0)
				return (-1);
		}
		if (format.b_zero)
		{
			if (ft_format_padding(format, &num, arg_value < 0 || format.b_space || format.b_plus) < 0)
				return (-1);
			if (ft_format_prefix(arg_value, format, &num) ==  -1)
				return (free (num), -1);
		}
		else
		{
			if (ft_format_prefix(arg_value, format, &num) ==  -1)
				return (free (num), -1);				
			if (ft_format_padding(format, &num, false) < 0)
				return (-1);
		}
		num_bytes = ft_iputstr_fd(num, fd);
		free (num);
		return (num_bytes);
	}
	else
		return (-1);
}
