/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:39 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:56:41 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

int	texture_init_one(t_data *data)
{
	data->env->n_wall->img = mlx_xpm_file_to_image(data->mlx, \
		data->map->textures[0], &data->env->n_wall->width, \
		&data->env->n_wall->height);
	if (!data->env->n_wall->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->env->n_wall);
	data->env->w_wall->img = mlx_xpm_file_to_image(data->mlx, \
		data->map->textures[1], &data->env->w_wall->width, \
		&data->env->w_wall->height);
	if (!data->env->w_wall->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->env->w_wall);
	data->env->s_wall->img = mlx_xpm_file_to_image(data->mlx, \
		data->map->textures[2], &data->env->s_wall->width, \
		&data->env->s_wall->height);
	if (!data->env->s_wall->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->env->s_wall);
	if (texture_init_two(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	texture_init_two(t_data *data)
{
	data->env->e_wall->img = mlx_xpm_file_to_image(data->mlx, \
		data->map->textures[3], &data->env->e_wall->width, \
		&data->env->e_wall->height);
	if (!data->env->e_wall->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->env->e_wall);
	return (EXIT_SUCCESS);
}
