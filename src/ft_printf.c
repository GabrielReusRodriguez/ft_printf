/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:30 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/24 01:25:27 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"
/*
static int ft_print_special_char(char c, va_list argp)
{
	if (c == 'c')
		return (ft_printf_char(argp));
	if (c == 's')
		return (ft_printf_str(argp));
	if (c == 'p')
		return (ft_printf_ptr(argp));
	if (c == 'd')
		return (ft_printf_dec(argp));
	if (c == 'i')
		return (ft_printf_int(argp));
	if (c == 'u')
		return (ft_printf_usgn(argp));
	if (c == 'x')
		return (ft_printf_low_hex(argp));		
	if (c == 'X')
		return (ft_printf_up_hex(argp));		
	if (c == '%')
		return (ft_printf_percent());
	return (0);
}
*/
/*
static char *ft_print_special_char(char const *str, char const *format, va_list argp)
{
	return (NULL);
}

static char *ft_get_format(char const *str)
{
	return (NULL);
}
*/

/*
static void	*free_ptr(char **ptr)
{
	if(*ptr != NULL)
	{
		free (*ptr);
		*ptr = NULL;
	}
	return (NULL);
}
*/
// The overall syntax of a conversion specification is:
//%[$][flags][width][.precision][length modifier]conversion

static char	*ft_get_next_chunk(char const *str)
{
	char	*chunk;
	char	*aux;
	size_t	len;
	size_t	size;
	
	size = ft_strlen(str);
	if (*str == '%')
	{
		
	}
	else
	{
		aux = ft_strchr(str,'%');
		if (aux == NULL)
			len = size;
		else
			len = aux - str;
		chunk = ft_substr(str, 0, len);
		free (aux);
	}
	return (chunk);
}

static char	*ft_treat_chunk(char const *buffer, char const *chunk,va_list argp)
{
	char	*new_buffer;

	//argp++;
	argp = argp;
	if (*chunk == '%')
	{

	}
	else
		new_buffer = ft_strjoin(buffer, chunk);
	return (new_buffer);
}

static char	*ft_new_buffer()
{
	char	*buffer;
	buffer = (char *)malloc(1);
	if (buffer == NULL)
		return(NULL);
	buffer[0] = '\0';
	return (buffer);
}

char	*ft_tostring(char const *str, va_list argp)
{
	size_t	i;
	size_t	len;
	char	*buffer;
	char	*chunk;
	char	*aux;
	
	i = 0;
	buffer = ft_new_buffer();
	if (buffer == NULL)
		return(NULL);
	while (str[i] != '\0')
	{
		chunk = ft_get_next_chunk(str + i);
		len = ft_strlen(chunk);
		aux = buffer;
		buffer = ft_treat_chunk(buffer, chunk, argp);
		free(aux);
		free(chunk);
		if(buffer == NULL)
			return (NULL);
		i = i + len;
	}
	return (buffer);
}

int ft_printf(char const *str, ...)
{
	va_list	argp;
	int		num_bytes;
	char	*buffer;
	
	num_bytes = 0;
	va_start(argp, str);
	buffer = ft_tostring(str,argp);
	if (buffer == NULL)
		return (-1);
	num_bytes = ft_iputstr_fd(buffer, 1);
	free(buffer);
	return (num_bytes);
	/*
	while(str[i] != '\0')
	{
		if (str[i] != '%')
			printed_bytes = ft_iputchar_fd(str[i],1);	
		else
		{
			printed_bytes = ft_print_special_char(str[i + 1], argp);
			i++;
		}
		if (printed_bytes >= 0)
			num_bytes = num_bytes + printed_bytes;
		i++;
	}
	*/
	va_end(argp);
	return (num_bytes);
}