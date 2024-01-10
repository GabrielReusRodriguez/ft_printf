/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:20:01 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 00:48:55 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*occurrence;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0')
	{
		if (*big == *little)
		{
			i = 1;
			occurrence = (char *)big;
			while (i < len && *big != '\0' && *little != '\0')
			{
				big++;
				little++;
				i++;
			}
			if (i == len || *little == '\0')
				return (occurrence);
		}
		big++;
	}
	return (NULL);
}
