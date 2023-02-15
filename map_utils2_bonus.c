/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:32:08 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:32:11 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	init_navmap(t_data *data)
{
	if (data->fnorm.startx < 0)
		data->fnorm.startx = 0;
	if (data->fnorm.starty < 0)
		data->fnorm.starty = 0;
}

void	fuck_norme(t_data *data)
{
	if (data->fnorm.startx < 0)
		data->fnorm.startx = 0;
	data->fnorm.x = 1;
	data->fnorm.y++;
	data->fnorm.starty++;
}
