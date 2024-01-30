/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/30 00:32:11 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_printf.h"

char	*ft_printf_usgn(va_list argp,  t_format	*format)
{
	unsigned int	arg_value;
	char			*ch_number;
	
	(void)format;
	arg_value = va_arg(argp, unsigned int);
	ch_number = ft_utoa(arg_value);
	return (ch_number);
}
