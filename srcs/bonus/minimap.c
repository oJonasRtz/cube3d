/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:04:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 12:59:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	show_the_art_to_godness(t_game *game, int s_y, int s_x, int color)
{
	int	y;
	int	x;

	s_y *= TILE_SIZE;
	s_x *= TILE_SIZE;
	if (!color)
		color = 0x000000;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
				s_x + x, s_y + y, color);
			x++;
		}
		y++;
	}
}

void	minimap(t_game *game)
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
			if (c != '\n')
				show_the_art_to_godness(game, index, count, color);
			count++;
		}
		index++;
	}
}
