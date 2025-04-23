/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:04:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 11:37:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	minimap(t_game *game)
{
	int		index;
	int		count;
	int		color;
	char	c;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		count = 0;
		while (game->true_game_map[index][count] != '\0')
		{
			c = game->true_game_map[index][count];
			if (c == '1')
				color = COLOUR_WALL;
			else if (c == '0')
				color = COLOUR_FLOOR;
			else if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
				color = COLOUR_PLAYER;
			mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
				count * TILE_SIZE, index * TILE_SIZE, color);
			count++;
		}
		index++;
	}
	return (0);
}
