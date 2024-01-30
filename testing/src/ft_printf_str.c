/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 20:32:45 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_printf.h"

char	*ft_printf_str(va_list argp, t_format *format)
{
	char	*str;
	
	if (format == NULL)
		return (NULL);
	str = va_arg(argp, char *);
	if (str == NULL)
	{
		//return (ft_iputstr_fd("(null)", 1));
		str = (char *)malloc(6 + 1);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str,"(null)",7);
	}
	if (format == NULL)
		return (NULL);
	return (str);
	//return (ft_iputstr_fd(str, 1));
}
