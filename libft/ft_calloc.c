/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:23 by bloisel           #+#    #+#             */
/*   Updated: 2022/11/21 12:14:03 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	c = malloc(count * size);
	if (!c)
		return (NULL);
	ft_memset(c, 0, count * size);
	return (c);
}
