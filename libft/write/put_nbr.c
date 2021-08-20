/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:08:06 by slucas-s          #+#    #+#             */
/*   Updated: 2021/04/15 13:16:32 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"

static void	writenbr(long long nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		writenbr(nbr * -1, fd);
	}
	else if (nbr > 0)
	{
		writenbr(nbr / 10, fd);
		ft_putchar_fd('0' + (nbr % 10), fd);
	}
}

/* Writes int <nbr> in the file descripted by <fd> as chars. */
void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
		writenbr(nbr, fd);
}

/* Writes long int <nbr> in the file descripted by <fd> as chars. */
void	ft_putlong_fd(long nbr, int fd)
{
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
		writenbr(nbr, fd);
}
