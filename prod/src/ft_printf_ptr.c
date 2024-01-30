/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/30 01:03:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"

static char	*ft_ptoa(void *ptr, t_format *format)
{
	unsigned long long	ll_ptr;
	//unsigned long	ll_ptr;
	char			*str_ptr;
	char			*str_head;
	char			*aux;

	//ll_ptr = (unsigned long long)ptr;
	ll_ptr = (unsigned long long)ptr;
	str_head = ft_ptr_new_char_buffer(3);
	if (str_head == NULL)
		return (NULL);
	ft_strlcpy(str_head, "0x", 3);
	str_ptr = ft_printf_htoa(ll_ptr, 0, format);
	if (str_ptr == NULL)
		return (NULL);
	aux = str_ptr;
	str_ptr = ft_strjoin(str_head,str_ptr);
	free (str_head);
	free (aux);
	return (str_ptr);
}

/*
num_bytes = ft_iputstr_fd("(nil)", 1); linux version...
*/
char	*ft_printf_ptr(va_list argp,  t_format	*format)
{
	void	*ptr;
	char	*str_ptr;
	size_t	size;

	ptr = va_arg(argp, void *);
	if (ptr == NULL)
	{
		size = 3 + 1;
		str_ptr = ft_ptr_new_char_buffer(size);
		if (str_ptr == NULL)
			return (NULL);
		ft_strlcpy(str_ptr, "0x0", size);
	}
	else
		str_ptr = ft_ptoa(ptr, format);
	return (str_ptr);
}
