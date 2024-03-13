/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:41:22 by behnam            #+#    #+#             */
/*   Updated: 2023/07/11 15:04:46 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include<unistd.h>
// #include<stdio.h>

// void	ft_putchar(char a, int *len)
// {
// 	write(1, &a, 1);
//     (*len)++;
// }

// void	ft_hexadecimal(unsigned int a, int *len)
// {
// 	if (a >= 16)
// 		ft_hexadecimal(a / 16, len);
// 	if (a % 16 >= 10)
// 	{
// 		ft_putchar((a % 16) + 87);
// 		(*len)++;
// 	}
// 	else
// 	{
// 		ft_putchar(a % 16 + '0');
// 		(*len)++;
// 	}
// }

void	ft_pointers(size_t a, int *len)
{
	char	*base;
	char	*str;
	int		i;

	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (a == 0)
	{
		write (1, "0", 1);
		(*len)++;
		return ;
	}
	base = "0123456789abcdef";
	str = (char *)malloc(16 * (sizeof(char)));
	while (a != 0)
	{
		str[i] = base[a % 16];
		a = a / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
	free (str);
}

// int main(void)
// {
// 	char *a;
// 	int b = a;
// 	int i = 0;
// 	ft_pointers((size_t)b, &i);
// 	printf("%p\n", a);
// 	printf("\n%d\n", i);
// 	return 0;
// }
