/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:26:10 by behnam            #+#    #+#             */
/*   Updated: 2023/07/11 13:30:44 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>

void	ft_hexadecimal(unsigned int a, int *len);
void	ft_hexxadecimal(unsigned int a, int *len);
void	ft_nums(int a, int *len);
int		ft_printf(const char *str, ...);
void	ft_putchar(char a, int *len);
void	ft_strs(char *str, int *len);
void	ft_unints(unsigned int a, int *len);
void	ft_pointers(size_t a, int *len);

#endif