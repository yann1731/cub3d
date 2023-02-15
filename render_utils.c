/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:53:50 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:53:52 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	render_fps(t_data *data)
{
	render_ceiling(data);
	render_floor(data);
	dda_routine(data);
	mlx_put_image_to_window(data->mlx, data->window, \
		data->frame->img, 0, 0);
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
	mlx_hook(data->window, ON_KEYUP, 0, decel, data);
	move(data);
	my_clear_img(data->frame);
	render_fps(data);
	return (0);
}
