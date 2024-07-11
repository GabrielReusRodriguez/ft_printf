/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:06:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/12 00:27:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_printf_bonus.h"

/*
If we geet precision with numeric conversion, zero flag is ignored.
*/
int	ft_format_width(t_format format, char **str, bool sign_print)
{
	char	*padding;
	char	*formated_str;
	int		len;
	char	padding_char;

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
		if (ft_add_padding(format, str, padding_char, len) < 0)
			return (-1);
	}
	return (0);
}

/*
int	ft_format_width(t_format format, char **str, bool sign_print)
{
	char	*padding;
	char	*formated_str;
	int		len;
	char	padding_char;

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
		//ft_add_padding(t_format format, char **str, char padding_char, int len)

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
*/