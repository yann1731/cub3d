/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:14:43 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/18 16:14:45 by tgarriss         ###   ########.fr       */
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
