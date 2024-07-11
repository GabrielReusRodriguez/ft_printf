/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:06:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/11 22:53:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_printf_bonus.h"

#include <stdio.h>
/*
If we geet precision with numeric conversion, zero flag is ignored.
*/
int	ft_format_padding(t_format format, char **str, bool sign_print)
{
	char	*padding;
	char	*formated_str;
	int		len;
	char	padding_char;

	//if (ft_strchr(NUMERIC_CONVERSION, format.c_conv_type) != NULL && format.b_dot)
	//	format.b_zero = false;
	if (format.n_width > 0)
	{
		if (format.b_zero)
			padding_char = '0';
		else
			padding_char = ' ';
		len = ft_strlen(*str);
		if (sign_print)
			len++;
		if ((int)format.n_width - len <= 0)
			return (0);
		padding = ft_calloc(sizeof(char), format.n_width + 1 - len);
		if (padding == NULL)
			return (-1);
		ft_memset(padding, padding_char, format.n_width - len);
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