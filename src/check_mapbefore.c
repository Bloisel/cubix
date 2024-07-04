/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapbefore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:31:22 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 03:33:22 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void check_map_is_before(t_data *dta)
{
    int i;

    i = 0;
    while (dta->map[i] && i < 6)
    {
        if (dta->map[i][0] == 'N' && dta->map[i][1] == 'O' && dta->map[i][2] == ' ')
            i++;
        if (dta->map[i][0] == 'S' && dta->map[i][1] == 'O' && dta->map[i][2] == ' ')
            i++;
        if (dta->map[i][0] == 'W' && dta->map[i][1] == 'E' && dta->map[i][2] == ' ')
            i++;
        if (dta->map[i][0] == 'E' && dta->map[i][1] == 'A' && dta->map[i][2] == ' ') 
            i++; 
        if (dta->map[i][0] == 'F' && dta->map[i][1] == ' ')
            i++;
        if (dta->map[i][0] == 'C' && dta->map[i][1] == ' ')
            i++;
        else
            printf_error(dta, "Error: Wrong elements in file .cub");
    }
}