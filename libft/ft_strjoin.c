/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:16:59 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/03 00:21:16 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str_joined = (char *)malloc(size_s1 + size_s2 + 1);
	if (str_joined == NULL)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		str_joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size_s2)
	{
		str_joined[size_s1 + i] = s2[i];
		i++;
	}
	return (str_joined);
}
