/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:34:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/11 00:47:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf_bonus.h"

/*With strings , precision printfs n firsts chars*/
static int	ft_format_string_precision(t_format format, char **str)
{
	char	*formated_str;

	if (format.n_precision >= 0)
	{
		formated_str = ft_substr(*str, 0, format.n_precision);
		if (formated_str == NULL)
			return (-1);
		free (*str);
		*str= formated_str;
	}
	return (0);
}

/* with numeric format and precision is informed, 0 flag is ignored*/
/* If it is numeric, we force the b_minus false and b_zero true flags 
because we have to add zeros to the left (less significant numbers)*/
static int	ft_format_numeric_precision(t_format format, char **str)
{
	char	padding_char;
	char	*padding;
	char	*formated_str;
	int		len;

	format.b_zero = true;
	format.b_minus = false;	
	if (format.n_precision > 0)
	{

		if (format.b_zero)
			padding_char = '0';
		else
			padding_char = ' ';
		len = ft_strlen(*str);
		if ((int)format.n_precision - len <= 0)
			return (0);
		padding = ft_calloc(sizeof(char), format.n_precision + 1 - len);
		if (padding == NULL)
			return (-1);
		ft_memset(padding, padding_char, format.n_precision - len);
		if (format.b_minus)
			formated_str = ft_strjoin(*str, padding);
		else
			formated_str = ft_strjoin(padding, *str);
		free (padding);
		if (formated_str == NULL)
			return (-1);
		free (*str);
		*str = formated_str;
	}
	return (0);	
}

int	ft_format_precision(t_format format, char **str)
{
	if (ft_strchr(NUMERIC_CONVERSION, format.c_conv_type) != NULL)
		return (ft_format_numeric_precision(format, str));
	if (ft_strchr("s", format.c_conv_type) != NULL)
		return (ft_format_string_precision(format, str));
	return (0);
}
