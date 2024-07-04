/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 00:14:07 by bloisel           #+#    #+#             */
/*   Updated: 2024/07/04 04:37:01 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void int_for_elem(t_data *dta)
{
    int no;
    int so;
    int we;
    int ea;

    no = 0;
    so = 0;
    we = 0;
    ea = 0;
    check_everything(dta, no, so , we, ea);
}

void check_everything(t_data *dta, int no, int so, int we, int ea)
{
    int i;
    int f;
    int c;

    i = 0;
    f = 0;
    c = 0;
    while (dta->map[i])
    {
        if (ft_strncmp(dta->map[i], "NO ", 3) == 0)
            no++;
        if (ft_strncmp(dta->map[i], "SO ", 3) == 0)
            so++;
        if (ft_strncmp(dta->map[i], "WE ", 3) == 0)
            we++;
        if (ft_strncmp(dta->map[i], "EA ", 3) == 0)
            ea++;
        if (ft_strncmp(dta->map[i], "F ", 2) == 0)
            f++;
        if (ft_strncmp(dta->map[i], "C ", 2) == 0)
            c++;
        i++;
    }
    if (no && so && we && ea && f && c > 1)
        printf_error(dta, "Error : elements in double");
    if (dta->error != 1)
        check_f(dta);
    if (dta->error != 1)
        check_c(dta);
}

