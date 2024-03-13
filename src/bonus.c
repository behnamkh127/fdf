/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:14:48 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/12 18:57:48 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	shift(float *next_x, float *next_y, t_fdf *data)
{
	*next_x += data->shift_x;
	*next_y += data->shift_y;
}

void	rotate_around_z(float *x, float *y, float angle)
{
	float	new_x;
	float	new_y;

	new_x = (*x) * cos(angle) - (*y) * sin(angle);
	new_y = (*x) * sin(angle) + (*y) * cos(angle);
	*x = new_x;
	*y = new_y;
}

void	rotate_around_x(float *y, int *z, float angle)
{
	float	new_y;
	float	new_z;

	new_y = (*y) * cos(angle) - (*z) * sin(angle);
	new_z = (*y) * sin(angle) + (*z) * cos(angle);
	*y = new_y;
	*z = new_z;
}

void	parallel_projection(float *x, float *y, int z, t_fdf *data)
{
	*x = *x * data->scale;
	*y = *y * data->scale - z;
}
