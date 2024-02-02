/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 13:41:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int ft_printf_str(va_list argp)
{
	char    *str;
	//size_t	size;

	str = va_arg(argp, char *);
	//size = ft_strlen(str);
	if(str != NULL)
		return (ft_iputstr_fd(str, 1));
	else
		return(ft_iputstr_fd("(null)", 1));
	
	//return (size);
}