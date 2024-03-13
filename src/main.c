/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:26:57 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/18 15:05:44 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*beh;

	beh = NULL;
	if (argc != 2)
	{
		ft_printf ("Arguments should be 2\n");
		return (1);
	}
	if (is_fdf_file(argv[1]) == 1)
	{
		ft_printf("Invalid file\n");
		exit(1);
	}
	beh = (t_fdf *)malloc(sizeof(t_fdf));
	readfile(argv[1], beh);
	beh->mlx = mlx_init();
	beh->win = mlx_new_window(beh->mlx, WIN_WIDTH, WIN_HEIGHT, "t_fdf");
	def_var(beh);
	start_point(beh);
	mlx_key_hook(beh->win, showkeys, beh);
	mlx_hook(beh->win, 2, 0, key_dest, NULL);
	mlx_hook(beh->win, 17, 0, win_close, NULL);
	mlx_loop(beh->mlx);
	return (0);
}

void	def_var(t_fdf *data)
{
	data->projection_mode = 0;
	data->zoom = 2;
	data->scale = 0;
	data->shift_x = 0;
	data->shift_y = 0;
	data->angle_z = 0.8;
	data->angle_x = 1;
	data->z = 0;
	data->next_z = 0;
}

void	start_point(t_fdf *data)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_new_image(data->mlx, WIN_WIDTH - 1, WIN_HEIGHT - 1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->bits_per_pixel = 4;
	draw(data, img);
}
