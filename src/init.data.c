/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:15:59 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/16 20:37:27 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_data(t_data *dta)
{
	dta->error = 0;
	dta->nb_l = 0;
	dta->start = 0;
	dta->map = NULL;
	dta->new_m = NULL;
	dta->size = 0;
	dta->res = 0;
	
	dta->img_height = 32;
	dta->img_width = 32;
	dta->player = 0;
	dta->longeur = 5;
	dta->largeur = 5;
	
	dta->p_posx = 0;
	dta->p_posy = 0;	
	dta->map2 = NULL;
	dta->buff = ft_calloc(10000, sizeof(char));
	dta->cm = NULL;
}
