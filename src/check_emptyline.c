/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_emptyline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:47:54 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/05 01:06:41 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_nol(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '1' && str[i] != '0')
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	checkstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] != '1')
			return (1);
		else
			return (0);
		i++;
	}
	return (1);
}

char	*check_noline(t_data *dta, int fd)
{
	int		i;
	int		idx;
	int		octet;
	char	char_read;

	i = ft_strlen(dta->buff);
	idx = 0;
	if ((fd < 0) || (i <= 0))
		return (NULL);
	octet = read(fd, &char_read, 1);
	while (octet > 0)
	{
		dta->buff[idx++] = char_read;
		if (char_read == '\n')
			break ;
		octet = read(fd, &char_read, 1);
	}
	if ((octet <= 0) && (idx == 0))
		return (free(dta->buff), NULL);
	dta->buff[idx] = '\0';
	return (dta->buff);
}

void	int_for_sline(t_data *dta, char **argv)
{
	int	fd;
	int	first_map;

	fd = 0;
	first_map = 0;
	search_line(dta, argv, fd, first_map);
}

int	search_line(t_data *dta, char **argv, int fd, int fisrt_map)
{
	char	*string;
	
	string = NULL;
	fd = open(argv[1], O_RDONLY);
	string = check_noline(dta, fd);
	while (string != NULL)
	{
		string = check_noline(dta, fd);
		if (string)
		{
			if (checkstr(string) == 0)
				fisrt_map = 1;
			if (fisrt_map == 1)
			{
				if (check_nol(string) == -1)
					printf_error(dta, "Error : empty line in map animal");
			}
		}
	}
	close(fd);
	return (0);
}
