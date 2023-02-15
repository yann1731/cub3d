/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:01:30 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 16:01:33 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	my_mlx_destroy_image(t_data *data, void *img)
{
	if (img)
		mlx_destroy_image(data->mlx, img);
}

void	x_free(void *tofree)
{
	if (tofree)
	{
		free(tofree);
		tofree = NULL;
	}
}

void	memclean(t_data *data)
{
	destroy_images(data);
	free_images(data);
}
