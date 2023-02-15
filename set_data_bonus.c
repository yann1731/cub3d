/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:03:33 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/19 10:19:32 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	set_vector(t_data *data)
{
	if (data->player->direction == 'N')
	{
		data->dda->dirx = 0;
		data->dda->diry = 1;
	}
	else if (data->player->direction == 'S')
	{
		data->dda->dirx = 0;
		data->dda->diry = -1;
	}
	else if (data->player->direction == 'W')
	{
		data->dda->dirx = 1;
		data->dda->diry = 0;
	}
	else
	{
		data->dda->dirx = -1;
		data->dda->diry = 0;
	}
}

void	set_plane(t_data *data)
{
	data->dda->planex = data->dda->diry * 0.66f;
	if (data->dda->dirx != 0)
		data->dda->planey = (data->dda->dirx * -0.66f);
	else
		data->dda->planey = 0.0f;
}

int	get_map_len(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	set_player(t_data *data)
{
	int	x;
	int	y;

	if (!data)
		return (EXIT_FAILURE);
	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (ft_isinset(data->map->map[y][x], "NWSE"))
			{
				data->dda->x = x + 0.5;
				data->dda->y = (data->map->height - y) + 0.5;
				data->player->direction = data->map->map[y][x];
				set_vector(data);
				set_plane(data);
			}
		x++;
		}
	y++;
	}
	return (EXIT_SUCCESS);
}
