/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 20:16:46 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include "ft_printf.h"


char	*ft_ptoa(void *ptr)
{
	unsigned long long	ll_ptr;
	size_t				size;
	char				*str;
	char				*hex_value;
	char				*hdr;

	ll_ptr = (unsigned long long)ptr;
	size = 2 + 1;
	hdr = (char *)malloc(size);
	if( hdr == NULL)
		return (NULL);
	ft_strlcpy(hdr,"0x",size);
	hex_value = ft_printf_htoa(ll_ptr, 0);
	if (hex_value == NULL)
	{
		free (hdr);
		return (NULL);
	}
	str = ft_strjoin(hdr, hex_value);
	free (hdr);
	free (hex_value);
	return (str);
}

char	*ft_printf_ptr(va_list argp)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(argp, void *);
	str = ft_ptoa(ptr);
	return (str);
}
