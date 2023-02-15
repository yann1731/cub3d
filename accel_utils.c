/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:23:40 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:23:44 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	accel_up(t_data *data)
{
	data->player->forward_accel = 0.035;
}

void	accel_down(t_data *data)
{
	data->player->rear_accel = 0.02;
}

void	accel_right(t_data *data)
{
	data->player->right_accel = 0.02;
}

void	accel_left(t_data *data)
{
	data->player->left_accel = 0.02;
}
