/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/26 18:38:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void print_map1(t_data *dta)
{
    int i;

    i = 0;
    while (dta->map[i])
    {
        printf("%s\n",dta->map[i]);
        i++; 
    }
}

int	is_sep(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

void mlcnew_map(t_data *dta, int size)
{
    char **str;
    int i;
    int res = dta->nb_l - dta->start;
    int start = dta->start;
    printf("res = %d\n", res);
    

    i = 0;
    str = malloc((sizeof(char *)) * (res  + 1));
    while(i < res)
    {
        str[start] = malloc(sizeof(char) * (size + 1));
        start++;
        i++;
    }
    i = 0;
    start = dta->start;
    while(i < res)
    {
        str[start] = ft_strdup(dta->map2[start]);
        printf("str la new map %s\n", str[start]);
        i++;
        start++;
    }
    i = 0;
    int j = 0;
    start = dta->start;
    while(i < res)
    {
        j = 0;
        while (str[start][j])
        {
            if (is_sep(str[start][j]) == 1)
                str[start][j] = 1;
            j++;
        }
        start++;
        i++;
    }
    printf("_______________________________________________________\n");
    i = 0;
    start = dta->start;
    while(i < res)
    {
        printf("str la new map %s\n", str[start]);
        i++;
        start++;
    }
}