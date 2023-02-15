/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:15:02 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/18 16:28:04 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	movement(int keycode, t_data *data)
{
	if (keycode == UPKEY)
		accel_up(data);
	if (keycode == DOWNKEY)
		accel_down(data);
	if (keycode == RIGHTKEY)
		accel_right(data);
	if (keycode == LEFTKEY)
		accel_left(data);
	if (keycode == LEFTARROW)
		accel_rotate_left(data);
	if (keycode == RIGHTARROW)
		accel_rotate_right(data);
}

void	move(t_data *data)
{
	move_up(data);
	move_down(data);
	move_right(data);
	move_left(data);
	rotate(data);
}

void	accel_rotate_right(t_data *data)
{
	data->player->accel_rotate = -0.02;
}

void	accel_rotate_left(t_data *data)
{
	data->player->accel_rotate = 0.02;
}

void	rotate(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dda->dirx;
	oldplanex = data->dda->planex;
	data->dda->dirx = data->dda->dirx * cos(data->player->accel_rotate) \
		- data->dda->diry * sin(data->player->accel_rotate);
	data->dda->diry = olddirx * sin(data->player->accel_rotate) + \
		data->dda->diry * cos(data->player->accel_rotate);
	data->dda->planex = data->dda->planex * \
		cos(data->player->accel_rotate) - data->dda->planey * \
		sin(data->player->accel_rotate);
	data->dda->planey = oldplanex * sin(data->player->accel_rotate) \
		+ data->dda->planey * cos(data->player->accel_rotate);
}
