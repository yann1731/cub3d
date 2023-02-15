/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:15:24 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/19 11:49:46 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	forge_structure(char **array, t_data *data)
{
	char	**tokens;
	int		i;

	if (!array || !data)
		return (EXIT_FAILURE);
	i = 0;
	while (array[i])
	{
		if (is_map(array[i]) == EXIT_FAILURE)
		{
			tokens = tokenize(array[i]);
			set_tokens(tokens, data);
			ft_free_carray(tokens);
		}
		else if (is_map(array[i]) == EXIT_SUCCESS)
			parse_map(array, &i, data);
		else
			ft_perror("unknown map setting", __FILE__, __func__, __LINE__);
		if (array[i])
			i++;
	}
	ft_free_carray(array);
	return (EXIT_SUCCESS);
}

int	validate_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!data->map->textures[i] || access(\
							data->map->textures[i], R_OK) == -1)
			return (EXIT_FAILURE);
	if (!data->map->fcolor || data->map->fcolor == -1)
		return (EXIT_FAILURE);
	if (!data->map->ccolor || data->map->ccolor == -1)
		return (EXIT_FAILURE);
	if (validate_map(data->map, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, \
						SCREENWIDTH, SCREENHEIGHT, "cub3d");
	data->frame->img = mlx_new_image(data->mlx, SCREENWIDTH + 1, \
		SCREENHEIGHT + 1);
	data->nav_map->img = mlx_new_image(data->mlx, SCREENWIDTH + 1, \
		SCREENHEIGHT + 1);
	my_get_data_addr(data->frame);
	data->frame->height = SCREENHEIGHT;
	data->frame->width = SCREENWIDTH;
	my_get_data_addr(data->nav_map);
	data->nav_map->height = SCREENHEIGHT;
	data->nav_map->width = SCREENWIDTH;
	data->player->forward_accel = 0;
	data->player->rear_accel = 0;
	data->player->right_accel = 0;
	data->player->left_accel = 0;
	data->player->accel_rotate = 0;
	data->dda->s_frame = 0;
	return (EXIT_SUCCESS);
}

int	parser(char *filepath, t_data *data)
{
	char	**array;

	if (check_filepath(filepath) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	array = read_file(filepath);
	if (!array)
		return (EXIT_FAILURE);
	if (forge_structure(array, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (!data->map->map)
		return (EXIT_FAILURE);
	if (set_player(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (validate_data(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (setup_mlx(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (texture_init_one(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
