/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 04:36:21 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/05 04:42:04 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_window(t_data *dta)
{
	//t_data	img;

	dta->mlx = mlx_init();
	dta->mlx_win = mlx_new_window(dta->mlx, dta->longeur * 32,
			dta->largeur * 32, "HELLO_WORLD");
}