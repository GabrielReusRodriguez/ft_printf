/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/06 00:41:15 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with strings . When we compile it gives you a "warning"*/
int	ft_printf_str(int fd, va_list argp, t_format format)
{
	char	*str;

	(void)format;
	str = va_arg(argp, char *);
	if (str != NULL)
		return (ft_iputstr_fd(str, fd));
	else
		return (ft_iputstr_fd("(null)", fd));
}
