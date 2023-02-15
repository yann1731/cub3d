/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:23:38 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/18 16:24:47 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_add_to_s(char *string, char c)
{
	char	*new_string;
	int		i;

	if (!c)
		return (string);
	if (!string)
	{
		new_string = ft_calloc(2, sizeof(char));
		new_string[0] = c;
	}
	else
	{
		new_string = ft_calloc(ft_strlen(string) + 2, sizeof(char));
		i = -1;
		while (string[++i])
			new_string[i] = string[i];
		new_string[i] = c;
		free(string);
	}
	return (new_string);
}
