/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:04:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/09 12:12:27 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

//The 0 flags is not used with chars because it compiles with warning.
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


/*Sign flags + and space do not have sense with char . When we compile it gives you a "warning"*/
int	ft_printf_char(int fd, va_list argp, t_format format)
{
	char	c;
	char	*str;
	int		num_bytes;

	(void)format;
	c = va_arg(argp, int);
	str = ft_calloc(sizeof(char), 2);
	if (str == NULL)
		return (-1);
	str[0] = c;
	if (ft_format_width(c, format, &str) < 0)
		return (free (str), -1);
	num_bytes = ft_iputstr_fd(str, fd);
	free (str);
	return (num_bytes);
}
