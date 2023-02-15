/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:50:32 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:50:34 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	clear_scaled_img(t_img *img, float scale)
{
	int	x;
	int	y;

	x = (SCREENWIDTH + 1) * scale;
	y = (SCREENHEIGHT + 1) * scale;
	while (--y > 0)
	{
		while (--x > 0)
		{
			my_mlx_pixel_put(img, x, y, 0x00000000);
		}
		x = SCREENWIDTH;
	}
}

void	render_fps(t_data *data)
{
	my_clear_img(data->nav_map);
	setup_navmap(data);
	image_scale_init(data, 0.3);
	render_ceiling(data);
	render_floor(data);
	dda_routine(data);
	mlx_put_image_to_window(data->mlx, data->window, \
		data->frame->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, \
		data->arm->img, (SCREENWIDTH / 2) - (data->arm->width / 2), \
			SCREENHEIGHT - data->arm->height);
	mlx_put_image_to_window(data->mlx, data->window, data->mmap->img, 0, 0);
	shooting(data);
}

void	render_map(t_data *data)
{
	my_clear_img(data->nav_map);
	setup_navmap(data);
	mlx_put_image_to_window(data->mlx, \
		data->window, data->nav_map->img, 0, 0);
}

int	decel(int keycode, t_data *data)
{
	(void) keycode;
	data->player->forward_accel = 0;
	data->player->rear_accel = 0;
	data->player->right_accel = 0;
	data->player->left_accel = 0;
	data->player->accel_rotate = 0;
	return (0);
}

int	render_loop(t_data *data)
{
	mlx_hook(data->window, ON_KEYDOWN, 0, handle_keypress, data);
	mlx_hook(data->window, ON_MOUSEMOVE, 0, get_mouse_pos, data);
	mlx_hook(data->window, ON_MOUSEDOWN, 0, mouse_down, data);
	mlx_hook(data->window, ON_KEYUP, 0, decel, data);
	move(data);
	my_clear_img(data->frame);
	if (data->map_open == false)
		render_fps(data);
	else
		render_map(data);
	return (0);
}
