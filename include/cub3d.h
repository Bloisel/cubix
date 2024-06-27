/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:01:33 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/27 21:26:09 by bloisel          ###   ########.fr       */
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
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
#include "MLX42/MLX42.h"

#define WIDTH 256
#define HEIGHT 256

typedef struct s_data
{
	char 	**new_m;
	char	**map;
	char	**map2;
	int		size;
	int 	res;
    int     nb_l;
	int		error;
	int start;
}	t_data;


//exit.prg
void	ft_exit(t_data *dta);
void	printf_error(t_data *dta, char *str);

// init_dta
void	init_data(t_data *dta);

//check.cub/la map
void	check_cub1(char **argv, t_data *dta);


// read//malloc/map
void	read_map(t_data *dta, char **argv);
void    make_wall(t_data *dta);
void    mall_map(t_data *dta);
void    size_mapline(t_data *dta);

//utils
void print_map1(t_data *dta);
int	is_sep(char c);
void mlc_fornewmap(t_data *dta, int len, int start, int res);
void mlcnew_map(t_data *dta, int len , int start, int res);
void intfor_newmap(t_data *dta);


#endif
