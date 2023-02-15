/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:46:04 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:46:06 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	move_up(t_data *data)
{
	data->dda->x += data->dda->dirx * data->player->forward_accel;
	data->dda->y += data->dda->diry * data->player->forward_accel;
	if (data->map->map[data->map->height - \
		(int) data->dda->y][(int) data->dda->x] == '1' \
		|| data->map->map[data->map->height - \
			(int) data->dda->y][(int) data->dda->x] == 'D')
	{
		data->dda->x -= data->dda->dirx * data->player->forward_accel;
		data->dda->y -= data->dda->diry * data->player->forward_accel;
	}
}

void	move_down(t_data *data)
{
	data->dda->x -= data->dda->dirx * data->player->rear_accel;
	data->dda->y -= data->dda->diry * data->player->rear_accel;
	if (data->map->map[data->map->height - (int) data->dda->y] \
		[(int) data->dda->x] == '1' || data->map->map[data->map->height \
			- (int) data->dda->y][(int) data->dda->x] == 'D')
	{
		data->dda->x += data->dda->dirx * data->player->rear_accel;
		data->dda->y += data->dda->diry * data->player->rear_accel;
	}
}

void	move_left(t_data *data)
{
	data->dda->x -= data->dda->diry * data->player->left_accel;
	data->dda->y -= -data->dda->dirx * data->player->left_accel;
	if (data->map->map[data->map->height - (int) data->dda->y] \
		[(int) data->dda->x] == '1' || data->map->map[data->map->height \
			- (int) data->dda->y][(int) data->dda->x] == 'D')
	{
		data->dda->x += data->dda->diry * data->player->left_accel;
		data->dda->y += -data->dda->dirx * data->player->left_accel;
	}
}

void	move_right(t_data *data)
{
	data->dda->x += data->dda->diry * data->player->right_accel;
	data->dda->y += -data->dda->dirx * data->player->right_accel;
	if (data->map->map[data->map->height - (int) data->dda->y] \
		[(int) data->dda->x] == '1' || data->map->map[data->map->height \
			- (int) data->dda->y][(int) data->dda->x] == 'D')
	{
		data->dda->x -= data->dda->diry * data->player->right_accel;
		data->dda->y -= -data->dda->dirx * data->player->right_accel;
	}
}

int	get_mouse_pos(int x, int y, t_data *data)
{
	double	olddirx;
	double	deltax;
	double	oldplanex;

	if (data->dda->oldx == 0)
		data->dda->oldx = x;
	olddirx = data->dda->dirx;
	oldplanex = data->dda->planex;
	deltax = (data->dda->oldx - x) * 0.005;
	data->dda->dirx = data->dda->dirx * \
		cos(deltax) - data->dda->diry * sin(deltax);
	data->dda->diry = olddirx * sin(deltax) + data->dda->diry * cos(deltax);
	data->dda->oldx = x;
	data->dda->planex = data->dda->planex * \
		cos(deltax) - data->dda->planey * sin(deltax);
	data->dda->planey = oldplanex * sin(deltax) + \
		data->dda->planey * cos(deltax);
	if (x < 0 || x > SCREENWIDTH || y < -30 || y > SCREENHEIGHT)
	{
		mlx_mouse_move(data->window, 512, 384);
		data->dda->oldx = 0;
	}
	return (0);
}
