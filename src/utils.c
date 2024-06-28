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
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void is_sepnoline(char c)
{
    if (c == '\n' || c == '\0')
		return (1);
	return (0);
}

int is_valid_char(char c) 
{
    return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

char	*ft_jointventure(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dup;

	dup = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dup)
		return (NULL);
	i = -1;
	j = -1;
	if (*s1 != '\0')
    {
        while (s1[++i])
		    dup[i] = s1[i];
        i--;
    }
	while (s2[++j])
		dup[++i] = s2[j];
	dup[i + 1] = '\0';
	return (dup);
}