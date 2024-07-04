/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:12:59 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 04:31:20 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void check_cubfile(char **argv, t_data *dta)
{
	int fd;

	if ((fd = open(argv[1], O_DIRECTORY)) != -1)
		printf_error(dta, "Error : ce fichier est un dossier\n");
}

void	check_cub1(char **argv, t_data *dta)
{
	int	i;
	int fd;

	i = ft_strlen(argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		printf_error(dta, "fichier invalide\n");
	if ((argv[1][i - 4] != '.' && argv[1][i - 3] != 'c' &&
			argv[1][i - 2] != 'u' && argv[1][i - 1] != 'b'))
		printf_error(dta, "Error : ce fichier n'est pas un point cub\n");
	check_cubfile(argv, dta);
}
