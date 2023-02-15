/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:27:41 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/18 16:27:43 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	get_mouse_pos(int x, int y, t_data *data)
{
	double	olddirx;
	double	deltax;
	double	oldplanex;

	if (data->dda->oldx == 0)
		data->dda->oldx = x;
	olddirx = data->dda->dirx;
	oldplanex = data->dda->planex;
	deltax = (data->dda->oldx - x) * 0.005;
	data->dda->dirx = data->dda->dirx * \
		cos(deltax) - data->dda->diry * sin(deltax);
	data->dda->diry = olddirx * sin(deltax) + data->dda->diry * cos(deltax);
	data->dda->oldx = x;
	data->dda->planex = data->dda->planex * \
		cos(deltax) - data->dda->planey * sin(deltax);
	data->dda->planey = oldplanex * sin(deltax) + \
		data->dda->planey * cos(deltax);
	if (x < 0 || x > SCREENWIDTH || y < -30 || y > SCREENHEIGHT)
	{
		mlx_mouse_move(data->window, 512, 384);
		data->dda->oldx = 0;
	}
	return (0);
}

void	rotate_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dda->dirx;
	oldplanex = data->dda->planex;
	data->dda->dirx = data->dda->dirx * cos(0.03) - data->dda->diry * sin(0.03);
	data->dda->diry = olddirx * sin(0.03) + data->dda->diry * cos(0.03);
	data->dda->planex = data->dda->planex * \
		cos(0.03) - data->dda->planey * sin(0.03);
	data->dda->planey = oldplanex * sin(0.03) + data->dda->planey * cos(0.03);
}

void	rotate_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dda->dirx;
	oldplanex = data->dda->planex;
	data->dda->dirx = data->dda->dirx * \
		cos(-0.03) - data->dda->diry * sin(-0.03);
	data->dda->diry = olddirx * sin(-0.03) + data->dda->diry * cos(-0.03);
	data->dda->planex = data->dda->planex * \
		cos(-0.03) - data->dda->planey * sin(-0.03);
	data->dda->planey = oldplanex * sin(-0.03) + data->dda->planey * cos(-0.03);
}
