/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:56:33 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/18 16:26:00 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	check_axis(t_data *data, int x, int y)
{
	int	axis;

	axis = 0;
	axis += check_left(data, x, y);
	axis += check_right(data, x, y);
	axis += check_up(data, x, y);
	axis += check_down(data, x, y);
	if (axis == 4)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	check_map_integrity(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (ft_isinset(data->map->map[y][x], "0NWSE"))
				if (check_axis(data, x, y) == EXIT_FAILURE)
					return (EXIT_FAILURE);
		x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	validate_map(t_map *map, t_data *data)
{
	int	y;
	int	x;
	int	player;

	player = 0;
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (!ft_isinset(map->map[y][x], "01NWSE"))
				return (EXIT_FAILURE);
			if (ft_isinset(map->map[y][x], "NWSE"))
				player++;
		}
	}
	if (player != 1)
		return (EXIT_FAILURE);
	if (check_map_integrity(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_map(char **tokens, int *i, t_data *data)
{
	char	*line;

	if (!tokens || !data || !i)
		return (EXIT_FAILURE);
	if (calculate_dimensions(tokens, i, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (tokens[(*i)])
	{
		line = fill_line(tokens[*i], data->map->width);
		data->map->map = ft_add_to_sarray(data->map->map, line, 1);
		(*i)++;
	}
	return (EXIT_SUCCESS);
}

int	is_map(char *line)
{
	int	i;
	int	j;

	if (!line)
		return (EXIT_FAILURE);
	i = 0;
	while (line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		j = -1;
		while (++j < 4)
			if (ft_strncmp(&line[i], get_wall(j), 2) == 0)
				return (EXIT_FAILURE);
		if (ft_strncmp(&line[i], "F", 1) == 0 || \
						ft_strncmp(&line[i], "C", 1) == 0)
			return (EXIT_FAILURE);
		else if (ft_isdigit(line[i]))
			return (EXIT_SUCCESS);
		else
			return (-1);
		if (line[i])
			i++;
	}
	return (EXIT_SUCCESS);
}
