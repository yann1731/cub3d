/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:02:27 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 16:02:29 by yannickst        ###   ########.fr       */
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
	x_free(data->env->n_wall);
	x_free(data->env->s_wall);
	x_free(data->env->w_wall);
	x_free(data->env->e_wall);
	x_free(data->env);
	x_free(data);
}

void	destroy_images(t_data *data)
{
	my_mlx_destroy_image(data, data->frame->img);
	my_mlx_destroy_image(data, data->env->n_wall->img);
	my_mlx_destroy_image(data, data->env->s_wall->img);
	my_mlx_destroy_image(data, data->env->w_wall->img);
	my_mlx_destroy_image(data, data->env->e_wall->img);
}
