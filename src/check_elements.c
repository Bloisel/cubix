/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 00:14:07 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 22:56:27 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	int_for_elem(t_data *dta)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	check_everything(dta, i, f);
}

void	check_everything(t_data *dta, int i, int f)
{
	while (dta->map[i])
	{
		if (ft_strncmp(dta->map[i], "NO ", 3) == 0)
			f++;
		if (ft_strncmp(dta->map[i], "SO ", 3) == 0)
			f++;
		if (ft_strncmp(dta->map[i], "WE ", 3) == 0)
			f++;
		if (ft_strncmp(dta->map[i], "EA ", 3) == 0)
			f++;
		if (ft_strncmp(dta->map[i], "F ", 2) == 0)
			f++;
		if (ft_strncmp(dta->map[i], "C ", 2) == 0)
			f++;
		i++;
	}
	if (f > 6)
		printf_error(dta, "Error : elements in double");
	if (dta->error != 1)
		check_f(dta);
	if (dta->error != 1)
		check_c(dta);
}
