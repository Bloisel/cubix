/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_emptyline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:47:54 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/03 23:18:45 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int check_nol(char *str)
{
    int i;

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

int checkstr(char *str)
{
    int i;

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

char *check_noline(t_data *dta, int fd)
{
    int          i;
    int      index;
    int      bytes;
    char character;

    i = ft_strlen(dta->buff);
    index = 0;
    if ((fd < 0) || (i <= 0))
		return (NULL);
    while ((bytes = read(fd, &character, 1)) > 0)
    {
	    dta->buff[index++] = character;
	    if (character == '\n')
		    break ;
    }
    if ((bytes <= 0) && (index == 0))
	    return (free(dta->buff), NULL);
    dta->buff[index] = '\0';
    return (dta->buff);
}

int	search_line(t_data *dta, int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;
    int     fisrt_map;

    fisrt_map = 0;
	line = 1;
	string = NULL;
	if (argc == 2)
	{
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
                        printf_error(dta,"Error : empty line in map animal");
                }
            }
			line++;
		}
		close(fd);
	}
	return (0);
}