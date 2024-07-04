/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:40:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 04:33:57 by bloisel          ###   ########.fr       */
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
	check_cub1(argv, &dta); // . cub
	read_map(&dta, argv); // read dup et split dta-map et dta-buff
	check_map_is_before(&dta); // check map before element
	// plus tard fonction verif element is valide vec open et pot .xpm
	int_for_elem(&dta);
	int_for_swall(&dta); // search wall pour variables verifie que map est presente 
	if (dta.error != 1)
	{
		intfor_newmap(&dta); // build new map a besoin des variable de search wall 
		check_map_walls(&dta); // a besoin de la new map valide pour checker les walls
	}
	search_line(&dta, argc, argv); // search ligne vide 
	if (dta.error != 1)
	{
	 	check_argmap(&dta);
		check_player(&dta);
	}
	free(dta.new_m);
	free(dta.map2);
	free(dta.map);
	return (0);
}
