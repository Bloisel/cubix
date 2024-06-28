/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:40:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/28 05:52:01 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_data dta;
	
	init_data(&dta);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2] , "--save", 10) != 0)
			ft_printf("%s\n", "Usage : ./cub3D [map.cub] (--save)");
		return (1);
	}
	if (argc > 3 || argc < 2)
	{
		ft_printf("%s\n", "Usage : ./cub3D [map.cub]");
		return (1);
	}
	check_cub1(argv, &dta);
	read_map(&dta, argv);
	check_map_walls(&dta);
	search_line(&dta, argc , argv);
	//print_map1(&dta);
	return (0);
}
