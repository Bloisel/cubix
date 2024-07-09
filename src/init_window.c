/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 04:36:21 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/09 14:43:30 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int close_window(void *param)
{
    t_data *dta = (t_data *)param;
    mlx_destroy_window(dta->mlx, dta->mlx_win);
    exit(0);
}

int dummy_loop(void *param)
{
    printf("Loop is running...\n");
    return (0);
}

void init_window(t_data *dta)
{
    printf("Trying to initialize mlx...\n");
    dta->mlx = mlx_init();
    if (dta->mlx == NULL) 
    {
        printf("Error: mlx_init failed\n");
        exit(1);
    }
    printf("mlx initialized successfully.\n");
    
    if (dta->longeur <= 0 || dta->largeur <= 0) 
    {
        printf("Error: Invalid window dimensions\n");
        exit(1);
    }

    printf("Creating window with dimensions: %d x %d\n", dta->longeur, dta->largeur);
    dta->mlx_win = mlx_new_window(dta->mlx, 1920, 1080, "Hello world!");
    
    if (dta->mlx_win == NULL) 
    {
        printf("Error: mlx_new_window failed\n");
        exit(1);
    }
    printf("Window created successfully.\n");

    // Ajout de hooks pour les événements clavier et fermeture de la fenêtre
    // mlx_hook(dta->mlx_win, 17, 0, close_window, dta); // Hook pour la fermeture de la fenêtre (17 est le code pour l'événement de fermeture)
    // mlx_loop_hook(dta->mlx, &dummy_loop, dta); // Hook pour la boucle principale
    mlx_loop(dta->mlx);
}



