/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:01:33 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/18 03:42:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H


# include"../libft/libft.h"
# include"../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <time.h>
# include "math.h"
# include <sys/types.h>
# include <sys/stat.h>
# include "../minilibx-linux/mlx.h"
# include "mlx.h"
//# include "../MLX42/include/MLX42/MLX42.h"
# include "mlx.h"

#define INTMAX 2147483647
//#define WIDTH 256
//#define HEIGHT 256

# define FOV 90
# define HEIGTH 480
# define WIDTH 640
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64

// typedef struct  s_img {
//     void        *img_ptr;
//     int         *data;
//     int         bpp;
//     int         size_l;
//     int         endian;
// }               t_img;

// typedef struct  s_mlx {
//     void        *mlx_ptr;
//     void        *win_ptr;
//     t_img       img;
// }               t_mlx;


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_posv
{
	int	x;
	int	y;
}t_posv;

typedef struct s_posd
{
	double	x;
	double	y;
}t_posd;

typedef struct s_plyr
{
	t_posv	case_pos;
	t_posd	pos;
	t_posd	plane;
	int		fov;
	double	dir;
	t_posd	rotation;
	int		speed;
}t_plyr;

typedef struct s_data
{
	char 	**cm;
	char 	*buff;
	char 	**new_m;
	char	**map;
	char	**map2;
	int		size;
	int 	res;
    int     nb_l;
	int		error;
	int 	start;
	int		player;

	double	p_posx;
	double 	p_posy;
	int		longeur;
	int		largeur;
	void	*mlx;
	void	*mlx_win;
	int		img_width;
	int		img_height;
	t_plyr	*plyr;
}	t_data;


// test mlx
int mainaux(t_data *dta);


//exit.prg
void	ft_exit(t_data *dta);
void	printf_error(t_data *dta, char *str);

// init_dta
void	init_data(t_data *dta);

//check.cub/la map
void	check_cub1(char **argv, t_data *dta);

//read_map read//malloc/map
void	read_map(t_data *dta, char **argv);

//utils
void print_new_mp(t_data *dta, int res);
int	is_sep(char c);
int is_sepnoline(char c);
int is_valid_char(char c); 
char	*ft_jointventure(char const *s1, char const *s2);

//new_map
void mlc_fornewmap(t_data *dta, int start, int res);
void mlcnew_map(t_data *dta, int start, int res, int i);
void intfor_newmap(t_data *dta);

//pars_wall
void	int_forcheckwalls(t_data *dta);
void	check_map_walls(t_data *dta, int x, int j, int i);

//check_emptyline
void	int_for_sline(t_data *dta, char **argv);
int		search_line(t_data *dta, char **argv, int fd, int fisrt_map);
char 	*check_noline(t_data *dta, int fd);
int 	check_nol(char *str);
int 	checkstr(char *str);

//search_wall
void int_for_swall(t_data *dta);
void    size_mapline(t_data *dta);
void    search_wall(t_data *dta, int i, int j, int k);

//check_mapbefore
void check_map_is_before(t_data *dta);

// check argument in map
void check_argmap(t_data *dta);
void check_player(t_data *dta);

// check elements avant map
void check_everything(t_data *dta, int i, int f);
void int_for_elem(t_data *dta);

// annexe elements pour C 245,0,100 et F 
void annex_utils2(t_data *dta, char *str);
void annex_utils(t_data *dta, char *str);
void check_f(t_data *dta);
void check_c(t_data *dta);


//init window try avec minilibx pas tres opti MLX42 sonne mieux mais fuck la bibli GLFW
void	init_window(t_data *dta);


#endif
