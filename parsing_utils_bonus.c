/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:08:22 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/19 10:19:19 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	*fill_line(char *line, int longest)
{
	char	*filled;
	int		diff;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	filled = NULL;
	while (line[i] && i < (int)ft_strlen(line) - 1)
	{
		if (ft_isspace(line[i]))
			filled = ft_add_to_s(filled, '1');
		else
			filled = ft_add_to_s(filled, line[i]);
		i++;
	}
	diff = longest - ft_strlen(filled);
	if (diff > 0)
		while (diff--)
			filled = ft_add_to_s(filled, '1');
	return (filled);
}

int	find_longest_line(char **tokens, int *i)
{
	int	len;
	int	j;

	j = (*i);
	len = ft_strlen(tokens[j]);
	while (tokens[j])
	{
		if ((int) ft_strlen(tokens[j]) > len)
		len = ft_strlen(tokens[j]);
		j++;
	}
	return (len);
}

int	calculate_dimensions(char **tokens, int *i, t_data *data)
{
	int	height;

	height = *i;
	while (tokens[height])
		height++;
	data->map->height = height - *i;
	data->map->width = find_longest_line(tokens, i) - 1;
	if (data->map->height <= 0 || data->map->width <= 0)
		return (EXIT_FAILURE);
	data->map->size = data->map->height * data->map->width;
	return (EXIT_SUCCESS);
}

int	check_filepath(char *filepath)
{
	int	len;

	len = ft_strlen(filepath);
	if (ft_strncmp(&filepath[len - 4], ".cub", 4) != 0)
	{
		ft_printf(STDERR_FILENO, "Error\ncub3d reads .cub maps\n");
		return (EXIT_FAILURE);
	}
	if (access(filepath, R_OK) == -1)
	{
		ft_printf(STDERR_FILENO, "Error\ncannot access() map\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

char	**read_file(char *filepath)
{
	char	**array;
	char	*line;
	int		fd;

	array = NULL;
	if (!filepath)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		array = ft_add_to_sarray(array, line, 1);
		line = get_next_line(fd);
	}
	close(fd);
	return (array);
}
