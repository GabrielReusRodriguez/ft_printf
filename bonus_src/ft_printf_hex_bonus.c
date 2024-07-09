/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:52:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/09 12:20:39 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with hex . When we compile it gives you a "warning"*/

static int	ft_format_hashtag(bool up_case, t_format format, char **str)
{

	char	*new_str;

	(void)format;
	if (format.b_hash)
	{
		if (up_case)
			new_str = ft_strjoin("0X", *str);
		else
			new_str = ft_strjoin("0x", *str);
		if (new_str == NULL)
			return (-1);
		free(*str);
		*str = new_str;
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

int	ft_printf_hex(int fd, unsigned long number, bool up_case, t_format format)
{
	char	*str;
	int		num_bytes;

	str = ft_htoa(number, up_case);
	if (str == NULL)
		return (-1);
	if (ft_format_hashtag(up_case, format, &str) < 0)
		return (free(str), -1);
	if (ft_format_width(number, format, &str) < 0)
		return (free (str), -1);
	num_bytes= ft_iputstr_fd(str, fd);
	free (str);
	return (num_bytes);
}
