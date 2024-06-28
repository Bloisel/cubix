/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maperror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:47:54 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/28 06:25:32 by bloisel          ###   ########.fr       */
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
        {
            printf("oh muchacho la y a une ligne vide dans la map va lire la consigne animal");
            printf("le numero %d\n", i);
            printf("la ligne %s\n", str);
            return (-1);
        }
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
        {
            printf("not the good line\n");
            return (1);
        }
        else
        {
            printf("first line of the map\n");
            printf("%s\n", str);
            return (0);
        }
        i++;
    } 
    return (1);
}

char *check_noline(t_data *dta, int fd)
{
    int i = ft_strlen(dta->buff);
    char *buffer;
    if ((fd < 0) || (i <= 0))
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (i + 1));
    int		index = 0;
    int		bytes;
    char	character;
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
			printf("Line %d - %s ", line, string);
			string = check_noline(dta, fd);
            if (string)
            {
                if (checkstr(string) == 0)
                    fisrt_map = 1;
                if (fisrt_map == 1)
                    check_nol(string);
            }
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF", line);
		close(fd);
	}
	return (0);
}