/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/25 20:17:24 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

typedef struct s_format
{
	unsigned char	b_left_aligment;
	unsigned char	b_signed_format;
	unsigned char	b_space_padding;
	unsigned char	b_zero_padding;
	unsigned char	b_alernate_form;
	unsigned char	b_max_num_chars;
	int				n_width;
	char			c_data_type;
	size_t			len;
}	t_format;

//int	ft_printf(char const *str, ...);
int			ft_printf(char const *str, ...);
char		*ft_printf_char(va_list argp);
char		*ft_printf_str(va_list argp, t_format *format);
char		*ft_printf_ptr(va_list argp);
char		*ft_printf_dec(va_list argp, t_format *format);
char		*ft_printf_int(va_list argp, t_format *format);
char		*ft_printf_usgn(va_list argp, t_format *format);
char		*ft_printf_low_hex(va_list argp, t_format *format);
char		*ft_printf_up_hex(va_list argp, t_format *format);
//int	ft_printf_hex(unsigned int number, unsigned int up_case, t_format *format);
char		*ft_printf_htoa(unsigned long long u_number, unsigned int up_case);
char		*ft_printf_percent(void);
char		*ft_printf_null_to_a();
t_format	*ft_printf_get_format(const char *str);
char		*ft_ptoa(void *ptr);

#endif