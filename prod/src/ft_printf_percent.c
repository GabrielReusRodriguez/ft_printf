/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:36 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/26 13:14:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_printf.h" 

char	*ft_printf_percent(void)
{
	char	*c;
	char	character;
	
	character = '%';
	c = ft_ptr_new_char_buffer(2);
	if (c == NULL)
		return (NULL);
	c[0] = character;
	c[1] = '\0';
	return (c);
}
