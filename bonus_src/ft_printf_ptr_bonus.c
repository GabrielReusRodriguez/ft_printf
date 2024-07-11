/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/12 00:22:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with PTR . 
	When we compile it gives you a "warning"*/
int	ft_printf_ptr(int fd, va_list argp, t_format format)
{
	int		num_bytes;
	void	*ptr;
	char	*hex_str;
	char	*formated_hex;

	(void)format;
	ptr = va_arg(argp, void *);
	if (ptr == NULL)
	{
		formated_hex = ft_strdup("(nil)");
		if (formated_hex == NULL)
			return (-1);
	}
	else
	{
		hex_str = ft_htoa((unsigned long long)ptr, false);
		if (hex_str == NULL)
			return (-1);
		formated_hex = ft_strjoin("0x", hex_str);
		free (hex_str);
		if (formated_hex == NULL)
			return (-1);
	}
	num_bytes = ft_iputstr_fd(formated_hex, fd);
	return (free(formated_hex), num_bytes);
}
