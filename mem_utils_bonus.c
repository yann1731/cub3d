/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:03:00 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 16:03:05 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	free_images(t_data *data)
{
	int	i;

	ft_free_carray(data->map->map);
	i = -1;
	while (++i < 4)
		x_free(data->map->textures[i]);
	x_free(data->map->textures);
	x_free(data->map);
	x_free(data->player);
	x_free(data->dda);
	x_free(data->frame);
	x_free(data->nav_map);
	x_free(data->env->n_wall);
	x_free(data->env->s_wall);
	free_images_two(data);
}

void	free_images_two(t_data *data)
{
	x_free(data->env->w_wall);
	x_free(data->env->e_wall);
	x_free(data->env);
	x_free(data->arm);
	x_free(data->door);
	x_free(data->shoot);
	x_free(data->carl);
	x_free(data->enemy->s1);
	x_free(data->enemy->s2);
	x_free(data->enemy->s3);
	x_free(data->enemy->s4);
	x_free(data->enemy);
	x_free(data->mmap);
	x_free(data);
}

void	destroy_images(t_data *data)
{
	my_mlx_destroy_image(data, data->frame->img);
	my_mlx_destroy_image(data, data->nav_map->img);
	my_mlx_destroy_image(data, data->env->n_wall->img);
	my_mlx_destroy_image(data, data->env->s_wall->img);
	my_mlx_destroy_image(data, data->env->w_wall->img);
	my_mlx_destroy_image(data, data->env->e_wall->img);
	my_mlx_destroy_image(data, data->arm->img);
	my_mlx_destroy_image(data, data->door->img);
	my_mlx_destroy_image(data, data->shoot->img);
	my_mlx_destroy_image(data, data->carl->img);
	my_mlx_destroy_image(data, data->enemy->s1->img);
	my_mlx_destroy_image(data, data->enemy->s2->img);
	my_mlx_destroy_image(data, data->enemy->s3->img);
	my_mlx_destroy_image(data, data->enemy->s4->img);
	my_mlx_destroy_image(data, data->mmap->img);
}
