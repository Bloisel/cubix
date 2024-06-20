/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:29:49 by bloisel           #+#    #+#             */
/*   Updated: 2022/12/09 15:21:04 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_new_print2(char c, long long arg, size_t *compteur)
{
	if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			*compteur += ft_putnbr_base(((unsigned int)arg),
					"0123456789abcdef");
		else
			*compteur += ft_putnbr_base(((unsigned int)arg),
					"0123456789ABCDEF");
	}
	if (c == 'p')
	{
		*compteur += ft_putstr("0x");
		*compteur += ft_putnbr_base2((unsigned long long)arg,
				"0123456789abcdef");
	}
}

void	ft_newprint(char c, long long arg, size_t *i, size_t *compteur)
{
	*i += 2;
	if (c == 'd' || c == 'i')
		*compteur += ft_putnbr((int)arg);
	if (c == 'c')
		*compteur += ft_putchar((char)arg);
	if (c == 's')
	{
		if (arg != 0)
				*compteur += ft_putstr((char *)arg);
		else
				*compteur += ft_putstr("(null)");
	}
	if (c == '%')
		*compteur += ft_putchar('%');
	if (c == 'u')
		*compteur += ft_putnbr_unsigned((unsigned int)arg);
	if ((c == 'p' || c == 'x' || c == 'X'))
		ft_new_print2(c, arg, compteur);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'
				|| str[i + 1] == 'p' || str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == 'i' || str[i + 1] == 's' || str[i + 1] == 'u'))
			ft_newprint(str[i + 1], va_arg(arg, long long), &i, &count);
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_newprint(str[i + 1], 1, &i, &count);
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
