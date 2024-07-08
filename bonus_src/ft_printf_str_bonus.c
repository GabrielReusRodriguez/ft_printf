/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/08 23:20:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with strings . When we compile it gives you a "warning"*/
int	ft_printf_str(int fd, va_list argp, t_format format)
{
	char	*str;
	char	*arg;
	int		num_bytes;

	(void)format;
	arg = va_arg(argp, char *);
	if (arg != NULL)
		str = ft_strdup(arg);
	else
		str = ft_strdup("(null)");
	if(str == NULL)
		return (-1);
	num_bytes = ft_iputstr_fd(str, fd);
	free (str);
	return (num_bytes);
}
