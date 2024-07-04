/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:04:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/05 01:13:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf_char(va_list argp)
{
	char	c;

	c = va_arg(argp, int);
	return (ft_iputchar_fd(c, 1));
}
