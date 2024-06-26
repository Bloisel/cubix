/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:31 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/26 18:25:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void mall_map(t_data *dta)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(dta->map[i][j] != '1')
        i++;
}



void    size_mapline(t_data *dta)
{
    int i = dta->start;
    int j;
    int k;
    int l = dta->nb_l;
    l--;
    k = ft_strlen(dta->map2[i]);
    while(i < l)
    {
        if (ft_strlen(dta->map2[i]) < ft_strlen(dta->map2[i + 1]))
        {
            if (k < ft_strlen(dta->map2[i + 1]))
                k = ft_strlen(dta->map2[i + 1]);
        }
        i++;
    }
    mlcnew_map(dta, k);
}


void    make_wall(t_data *dta)
{
   	int i;
	int j;
    
	i = 0;
	j = 0;
	while (dta->map2[i] && is_sep(dta->map2[i][j]) == 0 && dta->map2[i][j] != '1')
	{
		if (is_sep(dta->map2[i][0]) == 1)
		{
			while (dta->map2[i][j] && dta->map2[i][j] != '1')
			{
				if (dta->map2[i][j] == '1')
					break;
				j++;
			}
		}
		j = 0;
		i++;
	}
    dta->start = i;
    size_mapline(dta);
}    

void	read_map2(t_data *dta, int read_one, char *str, int fd)
{
	int	i;

	i = 0;
	str = ft_calloc(10000, sizeof(char));
	read_one = read(fd, str, 10000);
	if (read_one == -1)
	{
		free(str);
		printf_error(dta, "Error : le fichier n'a pas pu etre lu correctement");
	}
	dta->map = ft_split(str, '\n');
	dta->map2 = ft_split(str, '\n');
	free(str);
    i = 0;
    while(dta->map[i])
        i++;
    dta->nb_l = i;
    printf("nb de ligne %d\n", dta->nb_l);
    make_wall(dta);
}

void	read_map(t_data *dta, char **argv)
{
	char		*str;
	int			read_one;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf_error(dta, "Error : le fichier n'a pas pu etre ouvert");
	read_map2(dta, read_one, str, fd);
}

