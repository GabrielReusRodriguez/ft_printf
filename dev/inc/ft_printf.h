/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/05 14:55:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>

# define DATA_TYPE_CHAR		'c'
# define DATA_TYPE_STR		's'
# define DATA_TYPE_PTR		'p'
# define DATA_TYPE_DEC		'd'
# define DATA_TYPE_INT		'i'
# define DATA_TYPE_USG		'u'
# define DATA_TYPE_HEX_LOW	'x'
# define DATA_TYPE_HEX_UP	'X'
# define DATA_TYPE_PERCENT	'%'

int			ft_printf(char const *str, ...);
int			ft_printf_fd(int fd, char const *str, ...);
int			ft_printf_char(int fd, va_list argp);
int			ft_printf_str(int fd, va_list argp);
int			ft_printf_ptr(int fd, va_list argp);
int			ft_printf_dec(int fd, va_list argp);
int			ft_printf_int(int fd, va_list argp);
int			ft_printf_usgn(int fd, va_list argp);
int			ft_printf_hex(int fd, unsigned long number, bool up_case);
int			ft_printf_low_hex(int fd, va_list argp);
int			ft_printf_up_hex(int fd, va_list argp);
int			ft_printf_percent(int fd);

#endif