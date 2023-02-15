/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarriss <tgarriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:01:09 by tgarriss          #+#    #+#             */
/*   Updated: 2022/12/18 16:21:48 by tgarriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return (EXIT_FAILURE);
	while (haystack[i] != '\0' && i <= len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (EXIT_SUCCESS);
			j++;
		}
		i++;
	}
	return (EXIT_FAILURE);
}
