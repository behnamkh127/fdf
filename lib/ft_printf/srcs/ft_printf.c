/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:23:35 by bekhodad          #+#    #+#             */
/*   Updated: 2023/07/11 13:30:10 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_checkprint(char a, va_list *elements, int *len, int *i);

int	ft_printf(const char *str, ...)
{
	va_list	elements;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(elements, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_checkprint(str[++i], &elements, &len, &i);
			i++;
		}
		else
			ft_putchar((char)str[i++], &len);
	}
	va_end(elements);
	return (len);
}

static	void	ft_checkprint(char a, va_list *elements, int *len, int *i)
{
	if (a == 's')
		ft_strs(va_arg(*elements, char *), len);
	else if (a == 'i' || a == 'd')
		ft_nums(va_arg(*elements, int), len);
	else if (a == 'u')
		ft_unints(va_arg(*elements, unsigned int), len);
	else if (a == 'x')
		ft_hexadecimal(va_arg(*elements, unsigned int), len);
	else if (a == 'X')
		ft_hexxadecimal(va_arg(*elements, unsigned int), len);
	else if (a == 'p')
		ft_pointers(va_arg(*elements, size_t), len);
	else if (a == '%')
		ft_putchar('%', len);
	else if (a == 'c')
		ft_putchar(va_arg(*elements, int), len);
	else
		(*i)--;
}
