/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannickst-laurent <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:27:47 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/16 14:27:50 by yannickst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		destroy_window(data);
		destroy_images(data);
		free_images(data);
		exit(0);
	}
	else
		movement(keysym, data);
	return (0);
}
