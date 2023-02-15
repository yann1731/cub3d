/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:26:52 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:26:55 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

t_data	*init_struct(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (NULL);
	data->map->map = NULL;
	data->map->textures = ft_calloc(5, sizeof(char *));
	data->map->textures[4] = NULL;
	if (!data->map->textures)
		return (NULL);
	data->player = ft_calloc(1, sizeof(t_player));
	data->dda = ft_calloc(1, sizeof(t_dda));
	if (!data->dda || !data->player)
		return (NULL);
	return (data);
}

void	alloc_images(t_data *data)
{
	data->frame = ft_calloc(1, sizeof(t_img));
	data->env = ft_calloc(1, sizeof(t_env));
	data->env->n_wall = ft_calloc(1, sizeof(t_img));
	data->env->s_wall = ft_calloc(1, sizeof(t_img));
	data->env->w_wall = ft_calloc(1, sizeof(t_img));
	data->env->e_wall = ft_calloc(1, sizeof(t_img));
}
