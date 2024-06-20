/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:30:43 by bloisel           #+#    #+#             */
/*   Updated: 2022/12/09 16:21:26 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_word_unsigned(unsigned int nb)
{
	size_t	i;

	i = 0;
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

size_t	ft_putnbr_unsigned(unsigned int nbr)
{
	char	w;

	if (nbr > 9)
		ft_putnbr_unsigned(nbr / 10);
	w = (nbr % 10) + 48;
	write (1, &w, 1);
	return (ft_word_unsigned(nbr));
}
