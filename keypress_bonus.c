/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:27:20 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:27:25 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	set_map(int keycode, t_data *data)
{
	if (keycode == 46 && data->map_open == false)
	{
		data->map_open = true;
		return ;
	}
	if (keycode == 46 && data->map_open == true)
		data->map_open = false;
}

void	action(int keycode, t_data *data)
{
	double	mapx;
	double	mapy;

	mapx = data->dda->x;
	mapy = (double) data->map->height - data->dda->y;
	if (keycode == EKEY)
	{
		mapy += -data->dda->diry;
		mapx += data->dda->dirx;
		if (data->map->map[(int)(mapy + 1)][(int) mapx] == 'D')
		{
			data->map->map[(int)(mapy + 1)][(int) mapx] = 'O';
			return ;
		}
		if (data->map->map[(int)(mapy + 1)][(int) mapx] == 'O')
			data->map->map[(int)(mapy + 1)][(int) mapx] = 'D';
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		destroy_window(data);
		destroy_images(data);
		free_images(data);
		exit(0);
	}
	else
	{
		set_map(keysym, data);
		movement(keysym, data);
		action(keysym, data);
	}
	return (0);
}
