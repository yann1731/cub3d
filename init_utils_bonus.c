/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:26:19 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:26:23 by yannickst        ###   ########.fr       */
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
	data->nav_map = ft_calloc(1, sizeof(t_img));
	data->mmap = ft_calloc(1, sizeof(t_img));
	data->env = ft_calloc(1, sizeof(t_env));
	data->env->n_wall = ft_calloc(1, sizeof(t_img));
	data->env->s_wall = ft_calloc(1, sizeof(t_img));
	data->env->w_wall = ft_calloc(1, sizeof(t_img));
	data->env->e_wall = ft_calloc(1, sizeof(t_img));
	data->arm = ft_calloc(1, sizeof(t_img));
	data->door = ft_calloc(1, sizeof(t_img));
	data->shoot = ft_calloc(1, sizeof(t_img));
	data->carl = ft_calloc(1, sizeof(t_img));
	data->enemy = ft_calloc(1, sizeof(t_enemy));
	data->enemy->s1 = ft_calloc(1, sizeof(t_img));
	data->enemy->s2 = ft_calloc(1, sizeof(t_img));
	data->enemy->s3 = ft_calloc(1, sizeof(t_img));
	data->enemy->s4 = ft_calloc(1, sizeof(t_img));
}

void	shade_segment(t_data *data, int x)
{
	int	shade_ceiling;
	int	shade_floor;

	shade_ceiling = data->dda->drawstart - 5;
	shade_floor = data->dda->drawend + 5;
	if (data->dda->drawend != SCREENHEIGHT || data->dda->drawstart != 0)
	{
		while (shade_ceiling < data->dda->drawstart)
		{
			my_mlx_pixel_put(data->frame, x, \
				shade_ceiling, data->map->ccolor / 2);
			my_mlx_pixel_put(data->frame, x, \
				shade_floor, data->map->fcolor / 2);
			shade_ceiling++;
			shade_floor--;
		}
	}
}
