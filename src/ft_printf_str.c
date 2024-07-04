/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/04 22:13:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf_str(va_list argp)
{
	char	*str;

	str = va_arg(argp, char *);
	if (str != NULL)
		return (ft_iputstr_fd(str, 1));
	else
		return (ft_iputstr_fd("(null)", 1));
}
