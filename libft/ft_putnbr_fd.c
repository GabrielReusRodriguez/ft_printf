/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:45:22 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 00:55:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr(unsigned int n, int fd)
{
	char	digit;

	if (n < 10)
	{
		digit = '0' + n;
		write(1, &digit, 1);
		return ;
	}
	ft_putnbr(n / 10, fd);
	ft_putnbr(n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = n * (-1);
		write(fd, "-", 1);
	}
	else
		nbr = n;
	ft_putnbr(nbr, fd);
}
