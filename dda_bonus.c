/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:24:13 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:24:16 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	set_ray(t_data *data, int x)
{
	data->dda->camerax = 2 * (double) x / SCREENWIDTH - 1;
	data->dda->raydirx = data->dda->dirx + data->dda->planex \
		* data->dda->camerax;
	data->dda->raydiry = data->dda->diry + data->dda->planey \
		* data->dda->camerax;
	if (data->dda->raydirx == 0)
		data->dda->deltadistx = 1e30;
	else
		data->dda->deltadistx = fabs(1 / data->dda->raydirx);
	if (data->dda->deltadisty == 0)
		data->dda->deltadisty = 1e30;
	else
		data->dda->deltadisty = fabs(1 / data->dda->raydiry);
}

void	set_step(t_data *data)
{
	if (data->dda->raydirx < 0)
	{
		data->dda->stepx = -1;
		data->dda->sidedistx = (data->dda->x - data->dda->mapx) \
			* data->dda->deltadistx;
	}
	else
	{
		data->dda->stepx = 1;
		data->dda->sidedistx = (data->dda->mapx + 1 - data->dda->x) \
			* data->dda->deltadistx;
	}
	if (data->dda->raydiry < 0)
	{
		data->dda->stepy = -1;
		data->dda->sidedisty = (data->dda->y - data->dda->mapy) * \
			data->dda->deltadisty;
	}
	else
	{
		data->dda->stepy = 1;
		data->dda->sidedisty = (data->dda->mapy + 1 - data->dda->y) \
			* data->dda->deltadisty;
	}
}

void	do_dda(t_data *data)
{
	while (data->dda->hit == 0)
	{
		if (data->dda->sidedistx < data->dda->sidedisty)
			step_x(data);
		else
			step_y(data);
		if (data->dda->mapy > data->map->height || data->dda->mapy < 0)
			break ;
		if (data->map->map[data->map->height - data->dda->mapy] \
			[data->dda->mapx] == '1' \
			|| data->map->map[data->map->height - data->dda->mapy] \
				[data->dda->mapx] == 'D')
		{
			data->dda->hit = 1;
			if (data->map->map[data->map->height - data->dda->mapy] \
				[data->dda->mapx] == 'D')
				data->dda->door = true;
		}
	}
}

void	set_draw_len(t_data *data, int x)
{
	if (data->dda->side == 2 || data->dda->side == 3)
		data->dda->perpwalldist = \
			(data->dda->sidedistx - data->dda->deltadistx);
	else
		data->dda->perpwalldist = \
			(data->dda->sidedisty - data->dda->deltadisty);
	data->dda->lineheight = (int)(SCREENHEIGHT / data->dda->perpwalldist);
	data->dda->drawstart = (-data->dda->lineheight / 2) + (SCREENHEIGHT / 2);
	if (data->dda->drawstart < 0)
		data->dda->drawstart = 0;
	data->dda->drawend = (data->dda->lineheight / 2) + (SCREENHEIGHT / 2);
	if (data->dda->drawend >= SCREENHEIGHT)
		data->dda->drawend = SCREENHEIGHT - 1;
	if (data->dda->side == 0 || data->dda->side == 1)
		data->dda->hitwall = data->dda->x + \
			data->dda->perpwalldist * data->dda->raydirx;
	else
		data->dda->hitwall = data->dda->y + \
			data->dda->perpwalldist * data->dda->raydiry;
	data->dda->hitwall -= floor(data->dda->hitwall);
	shade_segment(data, x);
}

void	vert_slice(t_data *data, t_img *img, int x)
{
	double			y;
	unsigned int	color;
	double			ratio;
	double			width_ratio;

	y = 0;
	ratio = (double) img->height / (double) data->dda->lineheight;
	width_ratio = data->dda->hitwall * (double) img->width;
	while (data->dda->drawstart < data->dda->drawend)
	{
		if (data->dda->lineheight > SCREENHEIGHT)
			color = get_colors(img, width_ratio, (y + \
				((data->dda->lineheight - SCREENHEIGHT) / 2)) * ratio);
		else
			color = get_colors(img, width_ratio, y * ratio);
		my_mlx_pixel_put(data->frame, x, data->dda->drawstart, color);
		data->dda->drawstart++;
		y++;
	}
}
