/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:54:10 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:54:16 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	my_clear_img(t_img *img)
{
	int	x;
	int	y;

	x = SCREENWIDTH + 1;
	y = SCREENHEIGHT + 1;
	while (--y > 0)
	{
		while (--x > 0)
		{
			my_mlx_pixel_put(img, x, y, 0x00000000);
		}
		x = SCREENWIDTH;
	}
}

void	render_ceiling(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < (SCREENHEIGHT / 2))
	{
		while (++x < SCREENWIDTH)
		{
			my_mlx_pixel_put(data->frame, x, y, data->map->ccolor);
		}
		x = -1;
	}
}

void	render_floor(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = SCREENHEIGHT / 2;
	while (++y < SCREENHEIGHT)
	{
		while (++x < SCREENWIDTH)
		{
			my_mlx_pixel_put(data->frame, x, y, data->map->fcolor);
		}
		x = -1;
	}
}
