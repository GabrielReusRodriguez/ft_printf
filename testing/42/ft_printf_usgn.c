/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/24 18:21:29 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"

int	ft_printf_usgn(va_list argp)
{
	unsigned int	arg_value;
	char			*ch_number;
	int				num_bytes_wr;

	arg_value = va_arg(argp, unsigned int);
	ch_number = ft_utoa(arg_value);
	num_bytes_wr = ft_iputstr_fd(ch_number, 1);
	free (ch_number);
	return (num_bytes_wr);
}
