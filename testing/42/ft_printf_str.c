/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/24 18:28:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"

int	ft_printf_str(va_list argp)
{
	char	*str;

	str = va_arg(argp, char *);
	if (str == NULL)
		return (ft_iputstr_fd("(null)", 1));
	return (ft_iputstr_fd(str, 1));
}
