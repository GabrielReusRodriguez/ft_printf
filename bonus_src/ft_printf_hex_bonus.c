/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:52:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 14:31:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf_bonus.h"

char	*ft_printf_htoa(unsigned long u_number, unsigned int up_case, \
				t_format	*format)
{
	char			*str;

	str = ft_dtoh(u_number, up_case);
	if (str != NULL)
		str = ft_apply_hash_format(str, u_number, format);
	if (str != NULL)
		str = ft_apply_width(str, format);
	return (str);
}
