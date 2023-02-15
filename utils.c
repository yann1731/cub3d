/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:05:22 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/18 16:41:34 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	data->window = NULL;
	return (0);
}

int	convert_to_rgb(char *r, char *g, char *b)
{
	int	trgb[4];
	int	i;

	if (!r | !g | !b)
		return (-1);
	if (!ft_isint(r) || !ft_isint(g) || !ft_isint(b))
		return (-1);
	trgb[0] = 0;
	trgb[1] = ft_atoi(r);
	trgb[2] = ft_atoi(g);
	trgb[3] = ft_atoi(b);
	printf("%d %d %d\n", trgb[1], trgb[2], trgb[3]);
	i = -1;
	while (++i < 4)
		if (trgb[i] > 255 || trgb[i] < 0)
			return (-1);
	return (trgb[0] << 24 | trgb[1] << 16 | trgb[2] << 8 | trgb[3]);
}

char	*get_wall(int index)
{
	if (index == 0)
		return ("NO");
	if (index == 1)
		return ("WE");
	if (index == 2)
		return ("SO");
	if (index == 3)
		return ("EA");
	return (NULL);
}
