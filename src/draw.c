/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:12:24 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/18 15:07:10 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	linedrawing(t_fdf *data, t_img *img)
{
	float	x;
	float	y;

	x = data->x;
	y = data->y;
	put_z(data);
	zoom(&x, &y, data);
	zoom(&data->next_x, &data->next_y, data);
	find_color(data);
	if (data->projection_mode == 0)
	{
		make_3d(&x, &y, data->z, data);
		make_3d(&data->next_x, &data->next_y, data->next_z, data);
	}
	shift(&x, &y, data);
	shift(&data->next_x, &data->next_y, data);
	make_deltas(&x, &y, data);
	while ((int)(x - data->next_x) || (int)(y - data->next_y))
	{
		my_mlx_pixel_put(data, x, y, img);
		x += data->delta_x;
		y += data->delta_y;
	}
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, t_img *img)
{
	char	*pixel_addr;

	if (x >= 0 && x < WIN_WIDTH - 1 && y >= 0 && y < WIN_HEIGHT - 1)
	{
		pixel_addr = img->addr + (x * img->bits_per_pixel
				+ (y * img->line_length));
		*(int *) pixel_addr = data->color;
	}
}

void	draw(t_fdf *data, t_img *img)
{
	data->y = 0 ;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			if (data->x < (data->width - 1))
			{
				data->next_x = data->x + 1;
				data->next_y = data->y;
				linedrawing(data, img);
			}
			if (data->y < (data->height - 1))
			{
				data->next_x = data->x;
				data->next_y = data->y + 1;
				linedrawing(data, img);
			}
			(data->x)++;
		}
		(data->y)++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	free (img);
}

void	make_3d(float *x, float *y, int z, t_fdf *data)
{
	rotate_around_x(y, &z, data->angle_x);
	rotate_around_z(x, y, data->angle_z);
	*y = (*y) - z;
}

void	zoom(float *next_x, float *next_y, t_fdf *data)
{
	*next_x *= data->zoom;
	*next_y *= data->zoom;
}
