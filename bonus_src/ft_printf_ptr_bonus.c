/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/06 00:44:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "ft_printf_bonus.h"

/*Sign flags + and space do not have sense with PTR . When we compile it gives you a "warning"*/
static int	ft_ptoa(int fd, void *ptr, t_format format)
{
	unsigned long long	ll_ptr;
	size_t				num_bytes;

	ll_ptr = (unsigned long long)ptr;
	num_bytes = ft_iputstr_fd("0x", fd);
	num_bytes = num_bytes + ft_printf_hex(fd, ll_ptr, false, format);
	return (num_bytes);
}

int	ft_printf_ptr(int fd, va_list argp, t_format format)
{
	int		num_bytes;
	void	*ptr;

	ptr = va_arg(argp, void *);
	if (ptr == NULL)
		num_bytes = ft_iputstr_fd("(nil)", fd);
	else
		num_bytes = ft_ptoa(fd, ptr, format);
	return (num_bytes);
}
