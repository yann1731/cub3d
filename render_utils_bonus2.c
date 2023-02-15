/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:51:07 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:51:09 by yannickst        ###   ########.fr       */
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

int	mouse_down(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == 1 && data->map_open == false)
		data->dda->s_frame = 3;
	return (0);
}

void	shooting(t_data *data)
{
	if (data->dda->s_frame > 0)
	{
		mlx_put_image_to_window(data->mlx, data->window, \
			data->shoot->img, (SCREENWIDTH / 2) - (data->shoot->width / 2) + 5, \
				(SCREENHEIGHT - data->shoot->height) - 75);
		data->dda->s_frame--;
	}
}
