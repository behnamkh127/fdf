/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:24:20 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/18 12:47:49 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	getheight(char *name)
{
	int		fd;
	int		height;
	char	*c;

	height = 0;
	fd = open(name, O_RDONLY, 0);
	c = get_next_line(fd);
	while (c)
	{
		free (c);
		height++;
		c = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	getwidth(char *name)
{
	int		fd;
	size_t	width;
	char	*c;

	width = 0;
	fd = open(name, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_printf("Invalid file\n");
		exit(1);
	}
	c = get_next_line(fd);
	width = ft_wordcount(c, ' ');
	free (c);
	close(fd);
	return ((int) width);
}

void	fill_cordinate(int *z, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z[i] = ft_atoi(nums[i]);
		free (nums[i]);
		i++;
	}
	free (line);
	free (nums);
}

void	readfile(char *name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;
	int		j;

	j = 0;
	data->width = getwidth(name);
	data->height = getheight(name);
	data->z_cordinate = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z_cordinate[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		fill_cordinate(data->z_cordinate[j], line);
		j++;
		line = get_next_line(fd);
	}
	close (fd);
	data->z_cordinate[i] = NULL;
}

int	is_fdf_file(const char *filename)
{
	const char	*extension;
	size_t		i;

	extension = ".fdf";
	i = ft_strlen(filename);
	if (ft_strnstr(filename, extension, i) == NULL)
		return (1);
	else
		return (0);
}
