/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/24 01:25:04 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

# ifndef CONVERSION_SPECIFIER 
#  define CONVERSION_SPECIFIER "cspdiuxX%"
# endif

int		ft_printf(char const *, ...);
/*
char	*ft_printf_char(va_list argp);
char	*ft_printf_str(va_list argp);
char	*ft_printf_ptr(va_list argp);
char	*ft_printf_dec(va_list argp);
char	*ft_printf_int(va_list argp);
char	*ft_printf_usgn(va_list argp);
char	*ft_printf_low_hex(va_list argp);
char	*ft_printf_up_hex(va_list argp);
char	*ft_printf_hex(unsigned int arg, unsigned int up_case);
char	*ft_printf_percent();
*/
char	*ft_tostring(char const *str, va_list argp);
#endif