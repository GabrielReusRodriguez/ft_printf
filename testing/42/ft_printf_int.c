/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:14:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/24 18:19:15 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
		num_bytes = ft_iputstr_fd(num, 1);
	free (num);
	return (num_bytes);
}
