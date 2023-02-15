/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:47:06 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:47:09 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	move_up(t_data *data)
{
	data->dda->x += data->dda->dirx * data->player->forward_accel;
	data->dda->y += data->dda->diry * data->player->forward_accel;
}

void	move_down(t_data *data)
{
	data->dda->x -= data->dda->dirx * data->player->rear_accel;
	data->dda->y -= data->dda->diry * data->player->rear_accel;
}

void	move_left(t_data *data)
{
	data->dda->x -= data->dda->diry * data->player->left_accel;
	data->dda->y -= -data->dda->dirx * data->player->left_accel;
}

void	move_right(t_data *data)
{
	data->dda->x += data->dda->diry * data->player->right_accel;
	data->dda->y += -data->dda->dirx * data->player->right_accel;
}
