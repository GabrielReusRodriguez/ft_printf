/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/06 00:37:09 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with unsigned . When we compile it gives you a "warning"*/
int	ft_printf_usgn(int fd, va_list argp, t_format format)
{
	unsigned int	arg_value;
	char			*ch_number;
	int				num_bytes;

	(void)format;
	arg_value = va_arg(argp, unsigned int);
	ch_number = ft_utoa(arg_value);
	if (ch_number == NULL)
		return (-1);
	num_bytes = ft_iputstr_fd(ch_number, fd);
	free (ch_number);
	return (num_bytes);
}
