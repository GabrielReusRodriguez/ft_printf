/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 13:36:54 by greus-ro         ###   ########.fr       */
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

	arg_value = va_arg(argp,unsigned int);
	ch_number = ft_utoa(arg_value);
	if(ch_number == NULL)
		return (-1);
	num_bytes = ft_iputstr_fd(ch_number, 1);
	free (ch_number);
	return (num_bytes);
}