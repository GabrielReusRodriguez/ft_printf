/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/05 14:43:24 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_format
{
	unsigned char	b_minus;
	unsigned char	b_plus;
	unsigned char	b_space;
	unsigned char	b_zero;
	unsigned char	b_hash;
	unsigned char	b_precision;
	size_t			n_precision;
	size_t			n_width;
	char			c_data_type;
	size_t			len;
}	t_format;

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