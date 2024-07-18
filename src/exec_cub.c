/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:28:25 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/18 03:45:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int worldMap[mapWidth][mapHeight] = {
//     {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
//     {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
//     {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//     {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//     {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
//     {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
//     {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
//     {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
//     {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
//     {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
//     {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
//     {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
//     {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
//     {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//     {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
//     {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
//     {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
//     {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
//     {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
//     {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
//     {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
//     {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
//     {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
//     {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
// };



// void draw_vertical_line(t_mlx *mlx, int x, int drawStart, int drawEnd, int color) {
//     for (int y = drawStart; y < drawEnd; y++) {
//         mlx->img.data[y * screenWidth + x] = color;
//     }
// }

// void render(t_mlx *mlx, t_data *dta) 
// {
//     double posX = 22.0, posY = 11.5; // x and y start position
//     double dirX = -1.0, dirY = 0.0; // initial direction vector
//     double planeX = 0.0, planeY = 0.66; // the 2d raycaster version of camera plane

//     for (int x = 0; x < screenWidth; x++) {
//         // calculate ray position and direction
//         double cameraX = 2 * x / (double)screenWidth - 1; // x-coordinate in camera space
//         double rayDirX = dirX + planeX * cameraX;
//         double rayDirY = dirY + planeY * cameraX;

//         // which box of the map we're in
//         int mapX = (int)posX;
//         int mapY = (int)posY;

//         // length of ray from current position to next x or y-side
//         double sideDistX;
//         double sideDistY;

//         // length of ray from one x or y-side to next x or y-side
//         double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
//         double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
//         double perpWallDist;

//         // what direction to step in x or y-direction (either +1 or -1)
//         int stepX;
//         int stepY;

//         int hit = 0; // was there a wall hit?
//         int side; // was a NS or a EW wall hit?

//         // calculate step and initial sideDist
//         if (rayDirX < 0) {
//             stepX = -1;
//             sideDistX = (posX - mapX) * deltaDistX;
//         } else {
//             stepX = 1;
//             sideDistX = (mapX + 1.0 - posX) * deltaDistX;
//         }
//         if (rayDirY < 0) {
//             stepY = -1;
//             sideDistY = (posY - mapY) * deltaDistY;
//         } else {
//             stepY = 1;
//             sideDistY = (mapY + 1.0 - posY) * deltaDistY;
//         }
//         // perform DDA
//         while (hit == 0) {
//             // jump to next map square, either in x-direction, or in y-direction
//             if (sideDistX < sideDistY) {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//             } else {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//             }
//             // Check if ray has hit a wall
//             if (worldMap[mapX][mapY] > 0) hit = 1;
//         }

//         // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
//         if (side == 0) perpWallDist = (sideDistX - deltaDistX);
//         else           perpWallDist = (sideDistY - deltaDistY);

//         // Calculate height of line to draw on screen
//         int lineHeight = (int)(screenHeight / perpWallDist);

//         // calculate lowest and highest pixel to fill in current stripe
//         int drawStart = -lineHeight / 2 + screenHeight / 2;
//         if (drawStart < 0) drawStart = 0;
//         int drawEnd = lineHeight / 2 + screenHeight / 2;
//         if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

//         // choose wall color
//         int color;
//         switch (worldMap[mapX][mapY]) {
//             case 1:  color = 0xFF0000;  break; // red
//             case 2:  color = 0x00FF00;  break; // green
//             case 3:  color = 0x0000FF;  break; // blue
//             case 4:  color = 0xFFFFFF;  break; // white
//             default: color = 0xFFFF00;  break; // yellow
//         }

//         // give x and y sides different brightness
//         if (side == 1) { color = color / 2; }

//         // draw the pixels of the stripe as a vertical line
//         draw_vertical_line(mlx, x, drawStart, drawEnd, color);
//     }
// }

// int mainaux(t_data *dta) 
// {
//     t_mlx mlx;
//     mlx.mlx_ptr = mlx_init();
//     mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, screenWidth, screenHeight, "Raycaster");
//     mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, screenWidth, screenHeight);
//     mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);

//     render(&mlx, dta);

//     mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
//     mlx_loop(mlx.mlx_ptr);
//     return 0;
// }


void	po(t_plyr *plyr, char c)
{
	if (c == 'N')
	{
		plyr->dir = 270;
		plyr->plane.x = 0.66;
		plyr->plane.y = 0;
	}
	else if (c == 'E')
	{
		plyr->dir = 0;
		plyr->plane.x = 0;
		plyr->plane.y = 0.66;
	}
	else if (c == 'S')
	{
		plyr->dir = 90;
		plyr->plane.x = -0.66;
		plyr->plane.y = 0;
	}
	else if (c == 'W')
	{
		plyr->dir = 180;
		plyr->plane.x = 0;
		plyr->plane.y = -0.66;
	}
}

void	init_plyr_pos(t_plyr *plyr, int x, int y, char c)
{
	double	radian;

	plyr->case_pos.x = x;
	plyr->case_pos.y = y;
	po(plyr, c);
	plyr->pos.x = plyr->case_pos.x + 0.5;
	plyr->pos.y = plyr->case_pos.y + 0.5;
	radian = plyr->dir * (M_PI / 180);
	plyr->rotation.x = cos(radian);
	plyr->rotation.y = sin(radian);
}

void	init_aux(t_plyr *plyr, t_data *dta)
{
	int	x;
	int	z;

	plyr->case_pos.y = 0;
	x = 0;
	while (dta->new_m[x])
	{
		z = 0;
		while (dta->new_m[x][z])
		{
			if (dta->new_m[x][z] == 'N' || dta->new_m[x][z] == 'E'
				|| dta->new_m[x][z] == 'S' || dta->new_m[x][z] == 'W')
				init_plyr_pos(plyr, z, x, dta->new_m[x][z]);
			z++;
		}
		x++;
	}
	//sys->sizex = z;
	//sys->sizey = x;
	//sys->init_ok = 0;
}


int mainaux(t_data *dta)
{
    t_plyr	plyr;

	init_aux(&plyr, dta);
	dta->mlx = mlx_init();
	dta->plyr = &plyr;
	dta->mlx_win = mlx_new_window(dta->mlx, WIDTH, HEIGTH, "Cub5G");
	// init_texture(sys);
	// raycasting(sys, &player, 0);
	// mlx_hook()
	// mlx_hook()
	// mlx_hook()
	// mlx_loop_hook()
	// mlx_loop()
	return (1);
}