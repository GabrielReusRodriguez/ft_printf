/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:57:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 00:48:15 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		cmp = s1[i] - s2[i];
		if (cmp != 0)
			return (cmp);
		i++;
	}
	return (s1[i] - s2[i]);
}
