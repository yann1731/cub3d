/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:55:28 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/18 16:27:25 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	image_scale_init(t_data *data, float scale)
{
	float			x;
	float			y;
	unsigned int	color;

	data->mmap->width = data->nav_map->width * scale;
	data->mmap->height = data->nav_map->height * scale;
	if (!data->mmap->img)
	{
		data->mmap->img = mlx_new_image(data->mlx, \
			data->mmap->width, data->mmap->height);
		data->mmap->addr = mlx_get_data_addr(data->mmap->img,
				&data->mmap->bits_per_pixel, &data->mmap->size_line,
				&data->mmap->endian);
	}
	x = -1;
	while (++x < (data->nav_map->width * scale))
	{
		y = -1;
		while (++y < (data->nav_map->height * scale))
		{
			color = get_colors(data->nav_map, (x / scale), (y / scale));
			my_mlx_pixel_put(data->mmap, x, y, color);
		}
	}
}

unsigned int	get_colors(t_img *img, double x, double y)
{
	char	*dst;

	dst = img->addr + ((int) y * img->size_line + (int) x * \
											(img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_get_data_addr(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->size_line, &img->endian);
}

void	my_mlx_pixel_put(t_img *img, double x, double y, int color)
{
	char	*dst;

	dst = img->addr + ((int) y * img->size_line \
		+ (int) x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
