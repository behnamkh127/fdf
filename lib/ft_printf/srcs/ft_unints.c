/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behnam <behnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:24:00 by behnam            #+#    #+#             */
/*   Updated: 2023/07/08 12:35:32 by behnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include<unistd.h>
// #include<stdio.h>

// void	ft_putchar(char a)
// {
// 	write(1, &a, 1);
// }

void	ft_unints(unsigned int a, int *len)
{
	if (a >= 10)
		ft_unints(a / 10, len);
	ft_putchar(a % 10 + '0', len);
}

// int main(void)
// {
// 	unsigned int a = 2147483646;
// 	int i = 0;
// 	ft_unints(a, &i);
// 	printf("\n%d\n", i);
// 	return 0;
// }