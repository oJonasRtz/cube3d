/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_another.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:25:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/08 22:01:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	find_another(char **map, int index, char *target, int len)
{
	char	*find;

	find = NULL;
	++index;
	while (map[index] != NULL)
	{
		find = ft_strnstr(map[index], target, len);
		if (find != NULL)
			return (ft_putendl_fd_1("Error: Duplicate texture", 2));
		index++;
	}
	return (0);
}
