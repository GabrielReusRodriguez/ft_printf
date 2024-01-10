/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:41:37 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/02 23:48:58 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nbr)
{
	int	total;
	int	sign;

	sign = 1;
	while (*nbr != '\0' && (*nbr == '-' || *nbr == '+'))
	{
		if (*nbr == '-')
			sign = -sign;
		nbr++;
	}
	total = 0;
	while (*nbr != '\0')
	{
		if (*nbr >= '0' && *nbr <= '9')
			total = total * 10 + (*nbr - '0');
		else
			return (total * sign);
	}
	return (total * sign);
}
