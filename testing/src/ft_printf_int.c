/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:14:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 20:31:58 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_printf.h"

char	*ft_printf_int(va_list argp, t_format *format)
{
	int		arg_value;
	char	*num;

	if (format == NULL)
		return (NULL);
	arg_value = va_arg(argp, int);
	num = ft_itoa(arg_value);
	return (num);
}
