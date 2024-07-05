/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:47:38 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 23:54:58 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	size_mapline(t_data *dta)
{
	size_t	k;
	int		i;
	int		l;

	i = dta->start;
	l = dta->nb_l;
	k = ft_strlen(dta->map2[i]);
	l--;
	while (i < l)
	{
		if (ft_strlen(dta->map2[i]) < ft_strlen(dta->map2[i + 1]))
		{
			if (k < ft_strlen(dta->map2[i + 1]))
				k = ft_strlen(dta->map2[i + 1]);
		}
		i++;
	}
	dta->size = k;
}

void	int_for_swall(t_data *dta)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	search_wall(dta, i, j, k);
}

void	search_wall(t_data *dta, int i, int j, int k)
{
	while (dta->map[i])
	{
		j = 0;
		while (is_sep(dta->map[i][j] == 1))
		{
			if (dta->map[i][j] == '1')
			{
				k = 1;
				break ;
			}
			j++;
		}
		if (dta->map[i][0] == '1')
		{
			k = 1;
			break ;
		}
		i++;
	}
	if (k == 0)
		printf_error(dta, "Error : l'animal des tests sans map ou sans wall");
	dta->start = 6;
	size_mapline(dta);
}
