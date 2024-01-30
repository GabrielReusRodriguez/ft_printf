/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:53:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 03:02:42 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

static t_format	*ft_new_format(void)
{
	t_format	*format;

	format = (t_format *)malloc(sizeof(t_format));
	if (format == NULL)
		return (NULL);
	format->b_alernate_form = 0;
	format->c_data_type = ' ';
	format->b_left_aligment = 0;
	format->b_max_num_chars = 0;
	format->b_signed_format = 0;
	format->b_space_padding = 0;
	format->n_width = 0;
	format->b_zero_padding = 0;
	format->len = 0;
	return (format);
}

/*
if we get 0 we can differ which case is  if we have with 0 is the first  0 we get, is a flag
not a format. 
*/
static void	ft_update_format(char c, t_format *format)
{
	//printf("Analizando %c\n",c);
	if (c == '+')
		format->b_signed_format = 1;
	if (c == '#')
		format->b_alernate_form = 1;
	if (ft_isdigit(c) == 1)
	{
		//printf("isDIGIT\n");
		if(format->n_width == 0 && c == '0')
		{
			//printf("isZeroPadding\n");
			format->b_zero_padding = 1;
		}
		else
		{
			//printf("isWidth\n");
			format->n_width = format->n_width * 10 + ft_atoi(&c);
		}
	}
	if (c == '-')
		format->b_left_aligment = 1;
	if (c == ' ')
		format->b_space_padding = 1;
	if (c == '.')
		format->b_max_num_chars = 1;
	return ;
}

static int	ft_is_format_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p'\
		|| c == 'd' || c == 'i' || c == 'u'\
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

t_format	*ft_printf_get_format(const char *str)
{
	t_format	*format;
	size_t		i;

	format = ft_new_format();
	if (format == NULL)
		return (NULL);
	i = 1;
	while(str[i] != '\0' && ft_is_format_char(str[i]) == 0)
	{
		ft_update_format(str[i], format);
		i++;
	}
	if (str[i] != '\0')
		//format->c_data_type = str[i++];
		format->c_data_type = str[i];
	format->len = i + 1;
	return (format);
}
/*
#include <stdio.h>
static void	ft_printf_fotmat(t_format format)
{
	printf("Formato detectado:\n");
	return ;
}

int main(void)
{
	char *f="Gabriel Reus %-10d \n";
	t_format *format;
	size_t	i;
	i = 0;
	while( f[i] != '\0' && f[i] != '%')
		i++;
	format = ft_printf_get_format(f + i);
	printf("\tlen : %lu\n", format->len);
	printf("\twidth : %d\n", format->n_width);
	printf("\tzero padding : %d\n", format->b_zero_padding);
	return (0);
}
*/