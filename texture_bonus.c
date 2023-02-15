/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:08 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:56:11 by yannickst        ###   ########.fr       */
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
	if (enemy_texture_init(data) == EXIT_FAILURE)
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
	data->arm->img = mlx_xpm_file_to_image(data->mlx, \
		"assets/AK47.xpm", &data->arm->width, &data->arm->height);
	if (!data->arm)
		return (EXIT_FAILURE);
	my_get_data_addr(data->arm);
	data->door->img = mlx_xpm_file_to_image(data->mlx, \
		"assets/door.xpm", &data->door->width, &data->door->height);
	if (!data->door->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->door);
	data->shoot->img = mlx_xpm_file_to_image(data->mlx, \
		"assets/bloom.xpm", &data->shoot->width, \
		&data->shoot->height);
	if (!data->shoot->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->shoot);
	return (EXIT_SUCCESS);
}

int	enemy_texture_init(t_data *data)
{
	data->enemy->s1->img = mlx_xpm_file_to_image(data->mlx, \
		"assets/soldierf1.xpm", \
		&data->enemy->s1->width, &data->enemy->s1->height);
	if (!data->enemy->s1->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->enemy->s1);
	data->enemy->s2->img = mlx_xpm_file_to_image(data->mlx, \
		"assets/soldierf2.xpm", \
		&data->enemy->s2->width, &data->enemy->s2->height);
	if (!data->enemy->s2->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->enemy->s2);
	data->enemy->s3->img = mlx_xpm_file_to_image(data->mlx, \
		"assets/soldierf3.xpm", \
		&data->enemy->s3->width, &data->enemy->s3->height);
	if (!data->enemy->s3->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->enemy->s3);
	data->enemy->s4->img = mlx_xpm_file_to_image(data->mlx, \
		"assets/soldierf4.xpm", \
		&data->enemy->s4->width, &data->enemy->s4->height);
	if (!data->enemy->s4->img)
		return (EXIT_FAILURE);
	my_get_data_addr(data->enemy->s4);
	return (EXIT_SUCCESS);
}
