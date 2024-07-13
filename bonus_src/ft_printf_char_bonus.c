/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:04:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/14 01:02:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

//The 0 flags is not used with chars because it compiles with warning.

static	int	ft_format(t_format format, char **str)
{
	if (ft_format_width(format, str, false) < 0)
		return (-1);
	if (ft_format_precision(format, str) < 0)
		return (-1);
	return (0);
}

/*Sign flags + and space do not have sense with char . 
	When we compile it gives you a "warning"*/
/* Zero lag  does not have sense in char*/
int	ft_printf_char(int fd, va_list argp, t_format format)
{
	char	c;
	char	*str;
	int		num_bytes;

	format.b_zero = false;
	format.b_space = false;
	format.b_dot =  false;
	c = va_arg(argp, int);
	str = ft_calloc(sizeof(char), 2);
	if (str == NULL)
		return (-1);
	str[0] = c;
	if (ft_format(format, &str) < 0)
		return (free (str), -1);
	num_bytes = ft_iputstr_fd(str, fd);
	free (str);
	return (num_bytes);
}
