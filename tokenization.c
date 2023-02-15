/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:00:38 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/19 09:56:28 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	**tokenize(char *line)
{
	char	**tokens;
	char	*token;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	tokens = NULL;
	while (line[i])
	{
		token = NULL;
		while (line[i] && !ft_isspace(line[i]) && !ft_isinset(line[i], ","))
			token = ft_add_to_s(token, line[i++]);
		if (token)
			tokens = ft_add_to_sarray(tokens, token, 1);
		i++;
	}
	return (tokens);
}

int	set_color(char **tokens, t_data *data, int i)
{
	int	color;

	color = -1;
	if (ft_get_array_length(tokens) != 4)
	{
		data->map->fcolor = -1;
		data->map->ccolor = -1;
		return (EXIT_FAILURE);
	}
	color = convert_to_rgb(tokens[i + 1], tokens[i + 2], tokens[i + 3]);
	if (ft_strncmp(tokens[i], "F", 1) == 0)
		data->map->fcolor = color;
	else if (ft_strncmp(tokens[i], "C", 1) == 0)
		data->map->ccolor = color;
	return (EXIT_SUCCESS);
}

int	set_tokens(char **tokens, t_data *data)
{
	int	i;
	int	j;

	if (!tokens || !data)
		return (EXIT_FAILURE);
	i = -1;
	while (tokens[++i])
	{
		if (!tokens[i + 1])
			return (EXIT_FAILURE);
		j = -1;
		while (++j < 4)
		{
			if (ft_strncmp(tokens[i], get_wall(j), 2) == 0 && tokens[i + 1])
				data->map->textures[j] = ft_strdup(tokens[i + 1]);
		}
		if ((ft_isinset('F', tokens[i]) || ft_isinset('C', tokens[i])) && \
													ft_strlen(tokens[i]) == 1)
			set_color(tokens, data, i);
	}
	return (EXIT_SUCCESS);
}
