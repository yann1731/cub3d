/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:12:54 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/19 10:13:15 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	check_left(t_data *data, int x, int y)
{
	while (x >= 0)
	{
		if (data->map->map[y][x] == '1')
			return (1);
		x--;
	}
	return (0);
}

int	check_right(t_data *data, int x, int y)
{
	while (x < data->map->width)
	{
		if (data->map->map[y][x] == '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_up(t_data *data, int x, int y)
{
	while (y >= 0)
	{
		if (data->map->map[y][x] == '1')
			return (1);
		y--;
	}
	return (0);
}

int	check_down(t_data *data, int x, int y)
{
	while (y < data->map->height)
	{
		if (data->map->map[y][x] == '1')
			return (1);
		y++;
	}
	return (0);
}
