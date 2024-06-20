/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:47:27 by bloisel           #+#    #+#             */
/*   Updated: 2022/12/09 16:13:32 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_word(int nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		i = 1;
		nb *= -1;
	}
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

size_t	ft_putnbr(int nb)
{
	char	w;
	int		nb2;

	nb2 = nb;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (nb < 0)
		{
			write (1, "-", 1);
			nb *= -1;
		}
		if (nb > 9)
			ft_putnbr(nb / 10);
		w = (nb % 10) + 48;
		write (1, &w, 1);
	}
	return (ft_word(nb2));
}
