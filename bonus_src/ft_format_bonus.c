/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:43:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/12 00:38:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf_bonus.h"

static	void	ft_format_init(t_format *format)
{
	format->b_dot = false;
	format->b_hash = false;
	format->b_minus = false;
	format->b_plus = false;
	format->b_space = false;
	format->b_zero = false;
	format->c_conv_type = ' ';
	format->len = 0;
	format->n_precision = FORMAT_PRECISION_INIT;
	format->n_width = FORMAT_WIDTH_INIT;
}

static bool	ft_format_is_suported_type(char c)
{
	return (ft_strchr(SUPORTED_TYPES, c) != NULL);
}

static int	ft_format_get_width(const char *str, size_t *i, t_format *format)
{
	char	*substr;
	size_t	offset;
	int		num;

	offset = 0;
	while (str[*i + offset] != '\0' && ft_isdigit(str[*i + offset]) == 1)
		offset++;
	substr = ft_substr(str, *i, offset);
	if (substr == NULL)
		return (-1);
	num = ft_atoi(substr);
	free (substr);
	format->n_width = num;
	*i += offset;
	return (num);
}

/*
	The default precision is -1 but if we have the case %.d => the precision is 0.
*/
static int	ft_format_get_precision(const char *str, size_t *i, \
				t_format *format)
{
	char	*substr;
	size_t	offset;
	int		num;

	offset = 1;
	while (str[*i + offset] != '\0' && ft_isdigit(str[*i + offset]) == 1)
		offset++;
	if (offset == 1)
	{
		*i = *i + 1;
		format->n_precision = 0;
		return (0);
	}
	substr = ft_substr(str, *i + 1, offset - 1);
	if (substr == NULL)
		return (-1);
	num = ft_atoi(substr);
	free (substr);
	format->n_precision = num;
	*i += offset;
	return (num);
}

static	bool	ft_format_parse_prefix_flags(const char *str, size_t *j, \
					t_format *format)
{
	if (str[*j] == '+' || str[*j] == '#')
	{
		if (str[*j] == '+')
			format->b_plus = true;
		if (str[*j] == '#')
			format->b_hash = true;
		*j = *j + 1;
		return (true);
	}
	return (false);
}

static	bool	ft_format_parse_padding_flags(const char *str, size_t *j, \
					t_format *format)
{
	if (str[*j] == '-' || str[*j] == '0' || str[*j] == ' ')
	{
		if (str[*j] == '-')
			format->b_minus = true;
		if (str[*j] == '0')
			format->b_zero = true;
		if (str[*j] == ' ')
			format->b_space = true;
		*j = *j + 1;
		return (true);
	}
	if (str[*j] == '.')
	{
		format->b_dot = true;
		ft_format_get_precision(str, j, format);
		return (true);
	}
	if (ft_isdigit(str[*j]) == 1 && !format->b_dot)
	{
		ft_format_get_width(str, j, format);
		return (true);
	}
	return (false);
}

static void	ft_format_parse_flag(const char *str, size_t *j, t_format *format)
{
	if (ft_format_parse_prefix_flags(str, j, format))
		return ;
	ft_format_parse_padding_flags(str, j, format);
}

void	*ft_format_get(const char *str, t_format *format)
{
	size_t	j;

	j = 0;
	ft_format_init(format);
	while (str[j] != '\0' && !ft_format_is_suported_type(str[j]))
		ft_format_parse_flag(str, &j, format);
	format->len = j;
	if (ft_format_is_suported_type(str[j]))
		format->c_conv_type = str[j];
	else
		return (NULL);
	return (format);
}
