/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:04:16 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/12 00:33:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

int	ft_add_padding(t_format format, char **str, char padding_char, int len)
{
	char	*padding;
	char	*formated_str;

	padding = ft_calloc(sizeof(char), format.n_precision + 1 - len);
	if (padding == NULL)
		return (-1);
	ft_memset(padding, padding_char, format.n_precision - len);
	if (format.b_minus)
		formated_str = ft_strjoin(*str, padding);
	else
		formated_str = ft_strjoin(padding, *str);
	free (padding);
	if (formated_str == NULL)
		return (-1);
	free (*str);
	*str = formated_str;
	return (0);
}
