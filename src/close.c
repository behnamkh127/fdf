/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:21:28 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/19 13:50:00 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	key_dest(int key_code, t_fdf *data, t_img *img)
{
	if (key_code == 53)
	{
		if (data != NULL)
			mlx_destroy_window(data->mlx, data->win);
		free (data);
		free (img);
		exit (0);
	}
	return (0);
}

int	win_close(t_fdf *data, t_img *img)
{
	if (data != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		free (data);
		free (img);
	}
	exit (0);
}

int	showkeys(int key_code, t_fdf *data, t_img *img)
{
	int	i;

	ft_printf("%d\n", key_code);
	if (key_code == 126)
		data->shift_y -= 10;
	if (key_code == 125)
		data->shift_y += 10;
	if (key_code == 123)
		data->shift_x -= 10;
	if (key_code == 124)
		data->shift_x += 10;
	if (key_code == 6)
		data->zoom -= 2;
	if (key_code == 7)
		data->zoom += 2;
	if (key_code == 257 || key_code == 258)
		exit(0);
	i = key_code;
	project_angel(i, data);
	if (data->mlx != NULL && img->img != NULL)
		mlx_clear_window(data->mlx, data->win);
	start_point(data);
	return (0);
}

int	project_angel(int key_code, t_fdf *data)
{
	if (key_code == 35)
		data->projection_mode = 1;
	if (key_code == 34)
		data->projection_mode = 0;
	if (key_code == 13)
		data->angle_z -= 0.1;
	if (key_code == 1)
		data->angle_z += 0.1;
	if (key_code == 0)
		data->angle_x -= 0.1;
	if (key_code == 2)
		data->angle_x += 0.1;
	return (0);
}
