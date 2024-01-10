/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:53:52 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 00:49:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*occurrence;

	occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			occurrence = (char *)s;
		s++;
	}
	return (occurrence);
}
