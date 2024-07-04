/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:03:06 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/03 21:22:11 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	check_map_walls2(t_data *dta)
{
    int i;

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

void	check_map_walls(t_data *dta)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
    y = 0;
    x = 0;
    while (dta->new_m[x])
        x++;
    x--;
	while (dta->new_m[i])
	{
		while (dta->new_m[0][j])
		{
            if (dta->new_m[0][j] != '1')
            {
                ft_printf("First colonne de map pos :[0][%d]\n", j);
                printf_error(dta, "Error : la map n'est pas entouree de wall\n");
            }
            j++;
		}
        while (dta->new_m[x][y])
        {
            if (dta->new_m[x][y] != '1')
            {
                ft_printf("Last colonne de map pos :[%d][%d]\n", (x - 1), y);
                printf_error(dta, "Error : la map n'est pas entouree de wall\n");
            }
            y++;
        }
		i++;
	}
	check_map_walls2(dta);
}





