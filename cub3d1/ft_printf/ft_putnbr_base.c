/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:30:24 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/20 07:46:21 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wd_unsigned(unsigned int nb, int base)
{
	size_t	i;
	int m;

	m = nb;
	i = 0;
	if (m < 0)
	{
		i++;
		m = -1;
	}
	while (((unsigned int)m) >= ((unsigned int)base))
	{
		i++;
		m = m / base;
	}
	i++;
	return (i);
}

size_t	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_nb;

	base_nb = ft_strlen(base);
	if (nbr >= base_nb)
		ft_putnbr_base(nbr / base_nb, base);
	write (1, &base[(nbr % base_nb)], 1);
	return (ft_wd_unsigned(nbr, base_nb));
}
