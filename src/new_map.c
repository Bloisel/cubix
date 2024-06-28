/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:01:42 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/28 04:05:37 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void print_new_mp(t_data *dta, int res)
{
    int i = 0;
    while (i < res)
    {
        // printf("old ligne = %s\n", dta->map2[dta->start + i]);
        printf("new ligne = %s\n", dta->new_m[i]);
        printf("_______________________________________________________\n");
        i++;
    }
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
    dta->new_m[i] = '\0';
    //print_new_mp(dta, res);
    //free(dta->new_m);
}
