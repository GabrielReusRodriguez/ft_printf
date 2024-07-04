/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/05 00:02:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

int	ft_printf_usgn(va_list argp)
{
	unsigned int	arg_value;
	char			*ch_number;
	int				num_bytes;

	arg_value = va_arg(argp, unsigned int);
	ch_number = ft_utoa(arg_value);
	if (ch_number == NULL)
		return (-1);
	num_bytes = ft_iputstr_fd(ch_number, 1);
	free (ch_number);
	return (num_bytes);
}
