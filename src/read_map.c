/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:31 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 23:48:29 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	close(fd);
	dta->buff = ft_strdup(str);
	dta->map = ft_split(str, '\n');
	dta->map2 = ft_split(str, '\n');
	free(str);
	i = 0;
	while (dta->map[i])
		i++;
	dta->nb_l = i;
}

void	read_map(t_data *dta, char **argv)
{
	char		*str;
	int			read_one;
	int			fd;

	str = NULL;
	read_one = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf_error(dta, "Error : le fichier n'a pas pu etre ouvert");
	read_map2(dta, read_one, str, fd);
}
