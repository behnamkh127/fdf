/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_continue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:56:51 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/16 17:57:12 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	put_z(t_fdf *data)
{
	data->z = data->z_cordinate[(int)data->y][(int)data->x];
	data->next_z = data->z_cordinate[(int)data->next_y][(int)data->next_x];
}

void	make_deltas(float *x, float *y, t_fdf *data)
{
	data->delta_x = data->next_x - *x;
	data->delta_y = data->next_y - *y;
	data->max = find_max(do_abs(data->delta_x), do_abs(data->delta_y));
	data->delta_x /= data->max;
	data->delta_y /= data->max;
}

float	do_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	find_max(int x, int y)
{
	if (x < y)
		return (y);
	return (x);
}

void	find_color(t_fdf *data)
{
	if (data->z == 0 && data->next_z != 0)
		data->color = 0xffffff;
	else if (data->z != 0 && data->next_z != 0)
		data->color = 0xff00ff;
	else if (data->z != 0 && data->next_z == 0)
		data->color = 0x00ffff;
	else if (data->z == 0 && data->next_z == 0)
		data->color = 0xffff00;
	else
		data->color = 0x00ff00;
}
