/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:14:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/14 22:20:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"

int	ft_printf_int(va_list argp)
{
	int		num_bytes;
	int		arg_value;
	char	*num;

	num_bytes = 0;
	arg_value = va_arg(argp, int);
	num = ft_itoa(arg_value);
	if (num != NULL)
	{
		//num_bytes = ft_strlen(num);
		num_bytes = ft_iputstr_fd(num,1);
	}
	return (num_bytes);
}