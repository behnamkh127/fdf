/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behnam <behnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:21:39 by behnam            #+#    #+#             */
/*   Updated: 2023/07/08 12:50:41 by behnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strs(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}
