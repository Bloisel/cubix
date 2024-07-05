/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:35:00 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 22:46:44 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	annex_utils2(t_data *dta, char *str)
{
	int		i;
	int		at;
	char	**try;

	try = ft_split(str, ' ');
	i = 0;
	while (try[i])
		i++;
	if (i < 3 || i > 3)
		printf_error(dta, "Error : number either missing or added in elements");
	i = 0;
	at = 0;
	while (try[i])
	{
		at = ft_atoi(try[i]);
		if (at > 255 || at > INTMAX)
			printf_error(dta, "Error : Elements above range");
		at = 0;
		i++;
	}
	free(str);
	free(try);
}

void	annex_utils(t_data *dta, char *str)
{
	char	*string;
	int		i;
	int		j;

	i = ft_strlen(str);
	string = malloc(sizeof(char *) * i + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			string[j++] = str[i];
		if (str[i] == ',')
			string[j++] = 32;
		if (str[i] == 32)
			string[j++] = str[i];
		i++;
	}
	string[j] = '\0';
	free(str);
	annex_utils2(dta, string);
}

void	check_f(t_data *dta)
{
	int		i;
	int		j;
	int		k;
	char	*test;

	j = 0;
	i = 0;
	k = 0;
	while (dta->map[i])
	{
		if (ft_strncmp(dta->map[i], "F ", 2) == 0)
		{
			test = ft_strdup(dta->map[i]);
			while (dta->map[i][j])
			{
				if (dta->map[i][j] == ',')
					k++;
				j++;
			}
		}
		i++;
	}
	if (k > 2 || k <= 1)
		printf_error(dta, "Error : commas in element");
	annex_utils(dta, test);
}

void	check_c(t_data *dta)
{
	int		i;
	int		j;
	int		k;
	char	*test;

	j = 0;
	i = 0;
	k = 0;
	while (dta->map[i])
	{
		if (ft_strncmp(dta->map[i], "C ", 2) == 0)
		{
			test = ft_strdup(dta->map[i]);
			while (dta->map[i][j])
			{
				if (dta->map[i][j] == ',')
					k++;
				j++;
			}
		}
		i++;
	}
	if (k > 2 || k <= 1)
		printf_error(dta, "Error : commas in element");
	annex_utils(dta, test);
}
