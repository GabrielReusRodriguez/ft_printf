/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 13:31:55 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
//#include <stdio.h>
#include <stdlib.h>

/*
static int	ft_count_hex_chars(unsigned long long num)
{
	int	num_chars;

	num_chars = 1;
	while (num / 16 != 0)
	{
		num = num /16;
		num_chars++;
	}
	return (num_chars);
}
*/

static int ft_printf_hex_rec(unsigned long long ptr, unsigned int up_case)
{
	char	start_digit;
	int		num_bytes;

	num_bytes = 0;
	if (ptr < 10)
	{
		start_digit = '0';
		return (ft_iputchar_fd(start_digit + ptr, 1));
	}
	if(ptr < 16)
	{
		if (up_case == 1)
			start_digit = 'A';
		else
			start_digit = 'a';
		return (ft_iputchar_fd(start_digit + (ptr - 10), 1));
	}
	num_bytes = num_bytes + ft_printf_hex_rec(ptr / 16, up_case);
	num_bytes = num_bytes + ft_printf_hex_rec(ptr % 16, up_case);
	return (num_bytes);
}

static int ft_ptoa(void *ptr)
{
	unsigned long long	ll_ptr;
	size_t				num_bytes;

	ll_ptr = (unsigned long long)ptr;
	//number_bytes = ft_count_hex_chars(ll_ptr) + 2;
	num_bytes = ft_iputstr_fd("0x", 1);
	num_bytes = num_bytes + ft_printf_hex_rec(ll_ptr, 0);
	return (num_bytes);
}

int	ft_printf_ptr(va_list argp)
{
	int		num_bytes;
	void	*ptr;

	ptr = va_arg(argp, void *);
	if (ptr == NULL)
		num_bytes = ft_iputstr_fd("(nil)",1);
	else
		num_bytes = ft_ptoa(ptr);
	return (num_bytes);
}

/*
static int	ft_count_hex_chars(unsigned long long num)
{
	int	num_chars;

	num_chars = 1;
	while (num / 16 != 0)
	{
		num = num /16;
		num_chars++;
	}
	return (num_chars);
}


static void ft_printf_hex_rec(unsigned long long ptr, unsigned int up_case)
{
	char	start_digit;

	if (ptr < 10)
	{
		start_digit = '0';
		ft_putchar_fd(start_digit + ptr, 1);
		return ;
	}
	if(ptr < 16)
	{
		if (up_case == 1)
			start_digit = 'A';
		else
			start_digit = 'a';
		ft_putchar_fd(start_digit + (ptr - 10), 1);
		return ;
	}
	ft_printf_hex_rec(ptr / 16, up_case);
	ft_printf_hex_rec(ptr % 16, up_case);
}

static int ft_ptoa(void *ptr)
{
	unsigned long long	ll_ptr;
	size_t				number_bytes;

	ll_ptr = (unsigned long long)ptr;
	number_bytes = ft_count_hex_chars(ll_ptr) + 2;
	ft_putstr_fd("0x", 1);
	ft_printf_hex_rec(ll_ptr, 0);
	return (number_bytes);
}

int	ft_printf_ptr(va_list argp)
{
	int		num_bytes;
	void	*ptr;

	ptr = va_arg(argp, void *);
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)",1);
		num_bytes = ft_strlen("(nil)");
	}
	else
	{
		num_bytes = ft_ptoa(ptr);
	}
	return (num_bytes);
}
*/