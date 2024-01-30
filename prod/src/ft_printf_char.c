/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:04:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/30 01:00:54 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"

/*
va_arg pilla int pero NO acepta char como parametros.
*/
int	ft_printf_char(va_list argp)
{
	char	character;
	
	character = va_arg(argp, int);
	return (ft_iputchar_fd(character, 1));
}

/*
char	*ft_printf_char(va_list argp)
{
	char	*c;
	char	character;
	size_t	size;
	
	character = va_arg(argp, int);
	if (character != '\0')
		size = 2;
	else
		size = 1;
	c = (char *)malloc(size);
	if (c == NULL)
		return (NULL);
	c[size - 1] = '\0';
	if (size > 1)
		c[0] = character;
	return (c);
}
*/