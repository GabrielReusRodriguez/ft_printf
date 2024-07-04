/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/04 23:41:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_ptoa(void *ptr)
{
	unsigned long long	ll_ptr;
	size_t				num_bytes;

	ll_ptr = (unsigned long long)ptr;
	num_bytes = ft_iputstr_fd("0x", 1);
	num_bytes = num_bytes + ft_printf_hex(ll_ptr, false);
	return (num_bytes);
}

int	ft_printf_ptr(va_list argp)
{
	int		num_bytes;
	void	*ptr;

	ptr = va_arg(argp, void *);
	if (ptr == NULL)
		num_bytes = ft_iputstr_fd("(nil)", 1);
	else
		num_bytes = ft_ptoa(ptr);
	return (num_bytes);
}
