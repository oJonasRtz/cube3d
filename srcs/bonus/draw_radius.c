/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_radius.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:03:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/24 11:40:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_radius(t_game *game)
{
	int	index;
	int	px;
	int	py;

	index = 0;
	px = game->offset_x + (game->width / 2);
	py = game->offset_y + (game->heigth / 2);
	while (index < 1000)
	{
		game->map_pos_x = px / TILE_SIZE;
		game->map_pos_y = py / TILE_SIZE;
		if (px < 0 || py < 0
			|| game->map_pos_y >= game->heigth
			|| game->map_pos_x >= (int)ft_strlen(game->true_game_map[game->map_pos_y]))
			break ;
		if (game->true_game_map[game->map_pos_y][game->map_pos_x] == '1')
			break ;
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win, px,
		py, COLOUR_DEFAULT);
		px += game->dir_x;
		py += game->dir_y;
		index++;
	}
}
