/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:30 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 23:37:33 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"

/*
static int	ft_print_special_char(va_list argp, t_format *format)
{
	
	int	num_bytes;

	num_bytes = 0;
	//printf("\t\tVALOR: %c\n",format->c_data_type);
	if (format->c_data_type == 'c')
		num_bytes = ft_printf_char(argp);
	if (format->c_data_type == 's')
		num_bytes = ft_printf_str(argp, format);
	if (format->c_data_type == 'p')
		num_bytes = ft_printf_ptr(argp);
	if (format->c_data_type == 'd')
		num_bytes = ft_printf_dec(argp, format);
	if (format->c_data_type == 'i')
		num_bytes = ft_printf_int(argp, format);
	if (format->c_data_type == 'u')
		num_bytes = ft_printf_usgn(argp, format);
	if (format->c_data_type == 'x')
		num_bytes = ft_printf_low_hex(argp, format);
	if (format->c_data_type == 'X')
		num_bytes = ft_printf_up_hex(argp, format);
	if (format->c_data_type == '%')
		num_bytes = ft_printf_percent();
	return (num_bytes);
	
}

static int	ft_special_char(char **str, va_list argp, int pos)
{
	t_format	*format;
	int			num_bytes;
	char		*init_str;
	size_t		total_size;

	init_str = *str;
	total_size = ft_strlen(*str);
	format = ft_printf_get_format(*(str + pos));
	if(format == NULL)
	{
		return (-1);
	}
	num_bytes = ft_print_special_char(argp,format);
	//printf("\n\n\n\t str _%s_ start %lu pos %d len : %lu \n", str, format->len, pos,total_size);
	*str = ft_substr(init_str, pos + format->len, total_size - pos - format->len);
	if(*str == NULL)
	{
		free(format);
		return (-1);
	}
	free (init_str);
	free (format);
	return (num_bytes);
	
}

static int ft_printf_buffer(char *str, va_list argp)
{
	char	*string;
	int		printed_bytes;
	int 	num_bytes;
	size_t	i;

	string = ft_strdup(str);
	if(string == NULL)
		return (-1);
	i = 0;
	printed_bytes = 0;
	while (string[i] != '\0')
	{
		if (string[i] != '%')
			printed_bytes = ft_iputchar_fd(string[i], 1);
		else
		{
			//string = ft_special_char(string, argp, i, &printed_bytes);
			printed_bytes = ft_special_char(&string, argp, i);
			if(string == NULL)
			{
				return (-1);
			}
			i = -1;
		}
		if(printed_bytes == -1)
		{
			free (string);
			return (-1);
		}
		else
			num_bytes = num_bytes + printed_bytes;
		i++;
	}
	free (string);
	return (num_bytes);
}
*/

static char	*ft_new_empty_buffer(void)
{
	char	*buffer;

	buffer = (char *)malloc(1);
	if(buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	return (buffer);
}

void	*free_ptr(void *ptr)
{
	free(ptr);
	return (NULL);
}

/*
static char	*ft_process_body_special_char(const char *occurrence, char *buffer, t_format *format)
{
	
}
*/

static char	*ft_print_formated(const char *start_str, size_t *i, const char *occurrence, char *buffer)
{
	char	*head;
	char	*aux;
	char	*tmp;
	char	*body;
	size_t	len;
	
	printf("hhhh1\n");
	len = occurrence - start_str;
	head = ft_substr(start_str,0,len);
	if (head == NULL)
		return (NULL);
	aux = buffer;
	tmp = ft_strjoin(buffer, head);
	if (tmp == NULL)
		return (free_ptr(head));
	/*body = ft_process_body_special_char(occurrence,bufer, );
	aux = tmp;
	tmp = ft_strjoin(aux, body);
	if (tmp == NULL)
	{
		free (head);
		return (free_ptr(aux));
	}
	*/
	
	*i = *i + len + 1;
	printf("gggb1 i : %lu\n",*i);
	free (head);
	free (aux);
	return (tmp);
}

static char	*ft_update_buffer(const char *str, size_t *i, char *buffer)
{
	char	*aux;
	char	*end_chunk;
	size_t	size;

	size = ft_strlen(str + *i);
	aux = buffer;
	end_chunk = ft_strchr(str + *i,'%');
	printf("aaa1\n");
	if (end_chunk == NULL)
	{
		printf("bbbb1\n");
		buffer = ft_strjoin(buffer, str + *i);
		*i+= size;
	}
	else
	{
		printf("bbbb2 %lu\n",*i);
		buffer = ft_print_formated(str + *i, i, end_chunk, buffer);
		printf("ccc1\n");
	}
	printf("aaa2\n");
	free (aux);
	printf("aaa3\n");
	return (buffer);
}


static char	*ft_printf_create_buffer(const char *str, va_list argp)
{
	char	*buffer;
	size_t	i;
	size_t	size;
	char	*end_chunk;
	char	*aux;

	i = 0;
	size = ft_strlen(str);
	buffer = ft_new_empty_buffer();
	if (buffer == NULL)
		return (NULL);
	while (i < size)
	{
		aux = buffer;
		printf("aaa\n");
		buffer = ft_update_buffer(str, &i,buffer);
		printf("bbb\n");
		free(aux);
	}
	return (buffer);
	/*
	char	*string;
	int		printed_bytes;
	int 	num_bytes;
	size_t	i;

	string = ft_strdup(str);
	if(string == NULL)
		return (-1);
	i = 0;
	printed_bytes = 0;
	while (string[i] != '\0')
	{
		if (string[i] != '%')
			printed_bytes = ft_iputchar_fd(string[i], 1);
		else
		{
			//string = ft_special_char(string, argp, i, &printed_bytes);
			printed_bytes = ft_special_char(&string, argp, i);
			if(string == NULL)
			{
				return (-1);
			}
			i = -1;
		}
		if(printed_bytes == -1)
		{
			free (string);
			return (-1);
		}
		else
			num_bytes = num_bytes + printed_bytes;
		i++;
	}
	free (string);
	*/
}

int	ft_printf(char const *str, ...)
{
	va_list	argp;
	int		num_bytes;
	char	*buffer;
	size_t	size;

	num_bytes = 0;
	va_start(argp, str);
	buffer = ft_printf_create_buffer(str, argp);
	if (buffer == NULL)
		return (-1);
	size = ft_strlen(buffer);
	num_bytes = ft_iputstr_fd(buffer, 1);
	free(buffer);
	va_end(argp);
	return (num_bytes);
}


int main(void)
{
	//ft_printf("Hola mundo !\n",5);
	//ft_printf("Hola mundo %d !\n",5);
	char *string ="";
	//ft_printf("%s",string);
	ft_printf("GABRIEL REUS RODRIGUEZ%dGregorio Reus");
	return (0);
}

