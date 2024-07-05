/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:40:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/05 04:30:53 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



int main(int argc, char **argv)
{
	t_data dta;
	init_data(&dta);
	if (argc == 3)
	{
		// strlen argv + size --save
		if (ft_strncmp(argv[2] , "--save", 10) != 0)
			ft_printf("%s\n", "Usage : ./cub3D [map.cub] (--save)");
		return (1);
	}
	if (argc > 3 || argc < 2)
	{
		ft_printf("%s\n", "Usage : ./cub3D [map.cub]");
		return (1);
	}
	if (dta.error != 1)
	{
		check_cub1(argv, &dta); // check fichier .cub et pas dossier .cub
		read_map(&dta, argv); // read map strdup pour buff et split dta.map
		check_map_is_before(&dta); // check map before element split anhile les wh donc elements ordre strict si NO pas first error 
		// plus tard fonction verif element is valide vec open et pot .xpm .png
		int_for_elem(&dta); // verifie pas de doublons dans les elements 
		int_for_swall(&dta); // search wall verifier que wall present donc map 
		intfor_newmap(&dta); // build new map a besoin de variables de search wall 
		int_forcheckwalls(&dta); // check map entoure de wall a besoin de new map pour etre valide 
		int_for_sline(&dta, argv); // search ligne vide dans map 
		check_argmap(&dta); // search pas de wrong char in map genre 4 
		check_player(&dta); // verifier pas de doublons player 
	}
	free(dta.new_m);
	free(dta.map2);
	free(dta.map);
	return (0);
}

