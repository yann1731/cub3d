/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:28:06 by yannickst         #+#    #+#             */
/*   Updated: 2022/12/18 16:43:46 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_error("Error\nusage: './cub3d <path.cub>'" \
			, __FILE__, __func__, __LINE__);
	data = init_struct();
	alloc_images(data);
	if (!data)
	{
		ft_printf(STDERR_FILENO, "Error\ninitialization failed.\n");
		return (-1);
	}
	if (parser(argv[1], data) == EXIT_FAILURE)
	{
		ft_printf(STDERR_FILENO, "Error\nParser failed: Invalid map.\n");
		memclean(data);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(data->mlx, render_loop, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
