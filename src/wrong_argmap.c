/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_argmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:46:15 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/05 00:03:51 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_argmap(t_data *dta)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dta->new_m[i])
	{
		j = 0;
		while (dta->new_m[i][j])
		{
			if (dta->new_m[i][j] != '1' && dta->new_m[i][j] != '0'
				&& dta->new_m[i][j] != 'N' && dta->new_m[i][j] != 'S'
					&& dta->new_m[i][j] != 'E' && dta->new_m[i][j] != 'W')
			{
				ft_printf("map doesnt include this = %c\n", dta->new_m[i][j]);
				printf_error(dta, "Error : wrong arguments in map");
			}
			j++;
		}
		i++;
	}
}

void	check_player(t_data *dta)
{
	int	i;
	int	j;

	i = 0;
	while (dta->new_m[i])
	{
		j = 0;
		while (dta->new_m[i][j])
		{
			if (dta->new_m[i][j] == 'N' || dta->new_m[i][j] == 'S'
				|| dta->new_m[i][j] == 'E' || dta->new_m[i][j] == 'W')
				dta->player++;
			j++;
		}
		i++;
	}
	if (dta->player > 1)
		printf_error(dta, "Error : more than one players in map");
	if (dta->player == 0)
		printf_error(dta, "Error : there is no player and... that's a problem");
}
