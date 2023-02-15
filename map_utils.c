/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:13:43 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/18 16:13:46 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	my_put_player(t_data *data, int posx, int posy)
{
	int	x;
	int	y;
	int	startx;
	int	starty;

	y = 0;
	x = 0;
	startx = posx - 2;
	starty = posy - 2;
	player_ray(data, posx, posy);
	while (y < 5)
	{
		while (x < 5)
		{
			my_mlx_pixel_put(data->nav_map, startx, starty, 0x00FFFFFF);
			x++;
			startx++;
		}
		startx = posx - 2;
		x = 0;
		starty++;
		y++;
	}
}

void	player_ray(t_data *data, int posx, int posy)
{
	int		len;
	double	x;
	double	y;

	x = posx;
	y = posy;
	len = 25;
	while (len > 0)
	{
		my_mlx_pixel_put(data->nav_map, x, y, 0x00FF0000);
		x += data->dda->dirx;
		y += -data->dda->diry;
		len--;
	}
}

void	make_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	startx;
	int	starty;

	i = 0;
	j = 0;
	startx = x - 8;
	starty = y - 8;
	while (i < 16)
	{
		while (j < 16)
		{
			my_mlx_pixel_put(data->nav_map, startx, starty, color);
			j++;
			startx++;
		}
		startx = x - 8;
		j = 0;
		starty++;
		i++;
	}
}

void	display_routine(t_data *data)
{
	if (data->map->map[data->fnorm.starty][data->fnorm.startx] == '1')
		make_square(data, data->fnorm.x * 16, \
			data->fnorm.y * 16, 0x00FFFFFF);
	if (data->map->map[data->fnorm.starty][data->fnorm.startx] == 'D')
		make_square(data, data->fnorm.x * 16, \
			data->fnorm.y * 16, 0x3E00FF00);
	if (data->fnorm.startx == (int) data->dda->x && \
		data->fnorm.starty == (data->map->height - (int) data->dda->y))
		my_put_player(data, data->fnorm.x * 16, data->fnorm.y * 16);
	data->fnorm.x++;
	data->fnorm.startx++;
}

void	setup_navmap(t_data *data)
{
	data->fnorm.x = 1;
	data->fnorm.y = 1;
	data->fnorm.startx = data->dda->x - ((SCREENWIDTH / 16) / 2) + 0.5;
	data->fnorm.starty = ((data->map->height - data->dda->y) - 0.5) \
		- ((SCREENHEIGHT / 16) / 2);
	init_navmap(data);
	while (data->fnorm.y < (SCREENHEIGHT / 16) \
		&& data->map->map[data->fnorm.starty])
	{
		while (data->fnorm.x < (SCREENWIDTH / 16) \
			&& data->map->map[data->fnorm.starty][data->fnorm.startx])
			display_routine(data);
		data->fnorm.startx = data->dda->x - ((SCREENWIDTH / 16) / 2) + 0.5;
		fuck_norme(data);
	}
}
