/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:45:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/03 22:45:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	find_texture(char *high, char *little, int i)
{
	int		index;
	char	*find;

	index = 0;
	while (high[index] != '\n' && high[index] != '\0')
	{
		find = ft_strnstr(high, little, ft_strlen(high));
		if (find != NULL)
		{
			if (ft_strncmp(find, little, i) == 0)
				return (1);
		}
		index++;
	}
	return (0);
}
