/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:28:58 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 23:25:06 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_exit(t_data *dta)
{
	if (dta->error > 0)
		exit(1);
	exit(0);
}

void	printf_error(t_data *dta, char *str)
{
	ft_printf("%s\n", str);
	dta->error = 1;
	ft_exit(dta);
}
