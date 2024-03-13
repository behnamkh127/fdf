/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behnam <behnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:48:48 by behnam            #+#    #+#             */
/*   Updated: 2023/07/08 15:36:08 by behnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include<unistd.h>
// #include<stdio.h>

// void	ft_putchar(char a)
// {
// 	write(1, &a, 1);
// }

void	ft_nums(int a, int *len)
{
	if (a == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (a < 0)
	{
		ft_putchar('-', len);
		a *= -1;
	}
	if (a >= 10)
		ft_nums((a / 10), len);
	ft_putchar((a % 10) + '0', len);
}

// int main(void)
// {
// 	int a = -2147483647;
// 	int i = 0;
// 	ft_nums(a, &i);
// 	printf("\n%d\n", i);
// 	return 0;
// }