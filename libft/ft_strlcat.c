/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:09:55 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 00:48:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	return_size;
	size_t	i;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (dst_size < size)
		return_size = src_size + dst_size;
	else
		return_size = src_size + size;
	i = 0;
	while (i + dst_size < size - 1 && *src != '\0')
	{
		dst[i + dst_size] = src[i];
		i++;
	}
	dst[i + dst_size] = '\0';
	return (return_size);
}
