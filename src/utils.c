/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:37:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/27 19:43:27y bloisel          ###   ########.fr       */
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


void intfor_newmap(t_data *dta)
{
    int   res;
    int start;
    int   len;
    int ret;
    
    res = dta->nb_l - dta->start;
    start = dta->start;
    len = dta->nb_l;
    mlc_fornewmap(dta, len, start , res);
}


void mlc_fornewmap(t_data *dta, int len, int start, int res)
{
    int i;

    i = 0;
    dta->new_m = (char **)malloc((res + 1) * sizeof(char *));
    if (!dta->new_m) 
        printf_error(dta, "Error : memory allocation failed1\n");
    while (i++ < res)
        dta->new_m[i] = (char *)malloc((dta->size + 1) * sizeof(char));
    if (!dta->new_m[i]) 
        printf_error(dta, "Error : memory allocation failed2\n");
    mlcnew_map(dta, len, start, res);
}


void mlcnew_map(t_data *dta, int len , int start, int res)
{
    int i;
    int j;
    int k;
   
    j = 0;
    k = 0;
    i = 0;
    while (i < res)
    {
        j = 0;
        k = 0;
        while (dta->map2[start][j]) 
        {
            if (is_sep(dta->map2[start][j]) == 1)
                dta->new_m[i][k++] = '1';
            else
                dta->new_m[i][k++] = dta->map2[start][j];
            j++;
        }
        while (k < dta->size) 
            dta->new_m[i][k++] = '1';
        dta->new_m[i][k] = '\0';
        start++;
        i++;
    }
    i = 0;
    while (i < res)
    {
        printf("old ligne = %s\n", dta->map2[dta->start + i]);
        printf("new ligne = %s\n", dta->new_m[i]);
        printf("_______________________________________________________\n");
        i++;
    }
    i = 0;
    free(dta->new_m);
}
