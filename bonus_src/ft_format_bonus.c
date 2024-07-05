/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:43:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/06 00:28:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

static	void	ft_format_init(t_format *format)
{
	format->b_dot = false;
	format->b_hash = false;
	format->b_minus = false;
	format->b_plus = false;
	format->b_precision = false;
	format->b_space = false;
	format->b_zero = false;
	format->c_conv_type = ' ';
	format->len = 0;
	format->n_precision = 0;
	format->n_width = 0;
}

static bool	ft_format_is_suported_type(char c)
{
	return (ft_strchr(SUPORTED_TYPES, c) != NULL);
}

void	*ft_format_get(const char *str, t_format *format)
{
	size_t	j;
	
	j = 0;
	ft_format_init(format);
	while (str[j] != '\0' && !ft_format_is_suported_type(str[j]))
	{
		if (str[j] == '-')
			format->b_minus = true;
		if (str[j] == '0')
			format->b_zero = true;
		if (str[j] == ' ')
			format->b_space = true;
		if (str[j] == '+')
			format->b_plus = true;
		if (str[j] == '#')
			format->b_hash = true;
		if (str[j] == '.')
			format->b_dot = true;
		j++;
	}
	format->len = j;
	if (ft_format_is_suported_type(str[j]))
		format->c_conv_type = str[j];
	else
		return (NULL);
	return (format);
}
