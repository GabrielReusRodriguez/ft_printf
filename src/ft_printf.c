/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:56:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/08 23:52:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "../libft/libft.h"

static int	ft_print_special(char const *str, size_t pos_char, va_list ap)
{
	int		num_bytes;

	num_bytes = 0;
	return (num_bytes);
}

static int	ft_print_str(char const *str, va_list ap)
{
	int				num_bytes;
	size_t			i;

	num_bytes = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')			
				ft_putchar_fd('%', 1);
			else
				num_bytes = num_bytes + ft_print_special(str, i, ap) - 1;
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
		num_bytes++;
	}
	return (num_bytes);
}


int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int	num_bytes_printed;

	num_bytes_printed = 0;
	va_start(ap, str);
	va_end(ap);
	return (num_bytes_printed);
}




int	main(void)
{
	return (0);
}