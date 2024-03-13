/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:40:49 by behnam            #+#    #+#             */
/*   Updated: 2023/07/11 13:37:37 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include<unistd.h>
// #include<stdio.h>

// void	ft_putchar(char a)
// {
// 	write(1, &a, 1);
// }

static	int	ft_counter(unsigned int a, int b)
{
	while (a != 0)
	{
		a = a / 16;
		b++;
	}
	return (b);
}

void	ft_hexadecimal(unsigned int a, int *len)
{
	char	*base;
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	base = "0123456789abcdef";
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

// int main(void)
// {
// 	unsigned int a = 54092;
// 	int i = 0;
// 	ft_hexadecimal(a, &i);
// 	printf("\n%d\n", i);
// 	return 0;
// }