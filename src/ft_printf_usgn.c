/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/14 01:26:40 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"

int	ft_printf_usgn(va_list argp)
{
	unsigned int	arg_value;
	char			*ch_number;
	int				num_bytes;

	arg_value = va_arg(argp,unsigned int);
	ch_number = ft_utoa(arg_value);
	num_bytes = ft_strlen(ch_number);
	ft_putstr_fd(ch_number, 1);
	return (num_bytes);
}