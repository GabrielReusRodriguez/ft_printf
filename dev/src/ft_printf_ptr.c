/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/05 12:37:17 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_ptoa(int fd, void *ptr)
{
	unsigned long long	ll_ptr;
	size_t				num_bytes;

	ll_ptr = (unsigned long long)ptr;
	num_bytes = ft_iputstr_fd("0x", fd);
	num_bytes = num_bytes + ft_printf_hex(fd, ll_ptr, false);
	return (num_bytes);
}

int	ft_printf_ptr(int fd, va_list argp)
{
	int		num_bytes;
	void	*ptr;

	ptr = va_arg(argp, void *);
	if (ptr == NULL)
		num_bytes = ft_iputstr_fd("(nil)", fd);
	else
		num_bytes = ft_ptoa(fd, ptr);
	return (num_bytes);
}
