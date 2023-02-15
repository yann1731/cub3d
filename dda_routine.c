/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:25:29 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:25:32 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	init_dda_vars(t_data *data)
{
	data->dda->camerax = 0;
	data->dda->raydirx = 0;
	data->dda->raydiry = 0;
	data->dda->mapx = (int) data->dda->x;
	data->dda->mapy = (int) data->dda->y;
	data->dda->stepx = 0;
	data->dda->stepy = 0;
	data->dda->hit = 0;
	data->dda->lineheight = 0;
	data->dda->drawstart = 0;
}

void	dda_routine(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		init_dda_vars(data);
		set_ray(data, x);
		set_step(data);
		do_dda(data);
		set_draw_len(data, x);
		draw(data, x);
		x++;
	}
}

void	step_x(t_data *data)
{
	data->dda->sidedistx += data->dda->deltadistx;
	data->dda->mapx += data->dda->stepx;
	if (data->dda->stepx < 0)
		data->dda->side = 2;
	else
		data->dda->side = 3;
}

void	step_y(t_data *data)
{
	data->dda->sidedisty += data->dda->deltadisty;
	data->dda->mapy += data->dda->stepy;
	if (data->dda->stepy < 0)
		data->dda->side = 1;
	else
		data->dda->side = 0;
}

void	draw(t_data *data, int x)
{
	if (data->dda->side == 0)
		vert_slice(data, data->env->n_wall, x);
	if (data->dda->side == 1)
		vert_slice(data, data->env->s_wall, x);
	if (data->dda->side == 2)
		vert_slice(data, data->env->e_wall, x);
	if (data->dda->side == 3)
		vert_slice(data, data->env->w_wall, x);
}
