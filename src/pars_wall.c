/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:03:06 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 23:46:03 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_map_walls2(t_data *dta)
{
	int	i;

	i = 0;
	while (dta->new_m[i])
	{
		if (dta->new_m[i][0] != '1')
		{
			ft_printf("First char colonne pos [%d][0]\n", i);
			printf_error(dta, "Error : la map n'est pas entouree de wall\n");
		}
		if (dta->new_m[i][dta->size - 1] != '1')
		{
			ft_printf("Last char colonne pos :[%d][%d]\n", i, (dta->size - 1));
			printf_error(dta, "Error : la map n'est pas entouree de wall\n");
		}
		i++;
	}
}

void	int_forcheckwalls(t_data *dta)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	j = 0;
	i = 0;
	while (dta->new_m[x])
		x++;
	x--;
	check_map_walls(dta, x, j, i);
}

void	check_map_walls(t_data *dta, int x, int j, int i)
{
	int	y;

	y = 0;
	while (dta->new_m[i])
	{
		while (dta->new_m[0][j])
		{
			if (dta->new_m[0][j] != '1')
				printf_error(dta, "Error : la map n'est pas entouree de wall");
			j++;
		}
		while (dta->new_m[x][y])
		{
			if (dta->new_m[x][y] != '1')
				printf_error(dta, "Error : la map n'est pas entouree de wall");
			y++;
		}
		i++;
	}
	check_map_walls2(dta);
}
