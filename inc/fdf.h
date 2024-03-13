/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:20:27 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/18 15:04:44 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/ft_printf/includes/ft_printf.h"
#include "get_next_line.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define BUFF_SIZE 10
#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000

typedef struct s_fdf
{
	int		x_position;
	int		y_position;
	int		height;
	int		width;
	int		**z_cordinate;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	angle_z;
	float	angle_x;
	int		max;
	int		scale;
	int		projection_mode;
	float	x;
	float	y;
	float	delta_x;
	float	delta_y;
	float	next_x;
	float	next_y;
	int		z;
	int		next_z;
	void	*win;
	void	*mlx;
	int		is_mouse_pressed;
}	t_fdf;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	readfile(char *name, t_fdf *data);
void	linedrawing(t_fdf *data, t_img *img);
int		win_close(t_fdf *data, t_img *img);
int		key_dest(int key_code, t_fdf *data, t_img *img);
void	draw(t_fdf *data, t_img *img);
void	make_3d(float *x, float *y, int z, t_fdf *data);
int		showkeys(int key_code, t_fdf *data, t_img *img);
void	zoom(float *next_x, float *next_y, t_fdf *data);
void	shift(float *next_x, float *next_y, t_fdf *data);
void	find_color(t_fdf *data);
int		find_max(int x, int y);
float	do_abs(float x);
int		is_fdf_file(const char *filename);
void	parallel_projection(float *x, float *y, int z, t_fdf *data);
void	put_z(t_fdf *data);
void	make_deltas(float *x, float *y, t_fdf *data);
void	rotate_around_z(float *x, float *y, float angle);
void	rotate_around_x(float *y, int *z, float angle);
void	def_var(t_fdf *data);
int		project_angel(int key_code, t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, t_img *img);
void	start_point(t_fdf *data);
void	find_position(t_fdf *data);