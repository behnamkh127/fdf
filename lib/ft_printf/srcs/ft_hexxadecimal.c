/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexxadecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:27:50 by bekhodad          #+#    #+#             */
/*   Updated: 2023/07/11 13:40:54 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	ft_counter(unsigned int a, int b)
{
	while (a != 0)
	{
		a = a / 16;
		b++;
	}
	return (b);
}

void	ft_hexxadecimal(unsigned int a, int *len)
{
	char	*base;
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	base = "0123456789ABCDEF";
	if (a == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	count = ft_counter(a, count);
	str = (char *)malloc(count * (sizeof(char)));
	while (a != 0)
	{
		str[i++] = base[a % 16];
		a = a / 16;
	}
	while (i--)
		ft_putchar(str[i], len);
	free (str);
}
