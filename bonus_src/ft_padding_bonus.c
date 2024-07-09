/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:06:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/09 12:15:32 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_printf_bonus.h"

int	ft_format_padding(unsigned int value, t_format format, char **str)
{
	char	*padding;
	char	*formated_str;
	int		len;
	char	padding_char;

	(void)value;
	if (format.n_width > 0)
	{
		if (format.b_zero)
			padding_char = '0';
		else
			padding_char = ' ';
		len = ft_strlen(*str);
		if (format.n_width - len <= 0)
			return (0);
		padding = ft_calloc(sizeof(char), format.n_width + 1 - len);
		if (padding == NULL)
			return (-1);
		ft_memset(padding, padding_char, format.n_width - len);
		formated_str = ft_strjoin(padding, *str);
		free (padding);
		if (formated_str == NULL)
			return (-1);
		free (*str);
		*str = formated_str;
	}
	return (0);
}