/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:21:27 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/02 21:54:24 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	unsigned char	tmp;
	size_t			i;

	i = 0;
	dest_ptr = (unsigned char *) dest;
	src_ptr = (unsigned char *) src;
	while (i < n)
	{
		tmp = dest_ptr[i];
		dest_ptr[i] = src_ptr[i];
		src_ptr[i] = tmp;
		i++;
	}
	return (dest);
}
