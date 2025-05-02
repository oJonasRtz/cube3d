/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:22:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/02 18:08:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	can_move(t_game *game, double next_x, double next_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(next_x + (game->width / 2)) / TILE_SIZE;
	map_y = (int)(next_y + (game->heigth / 2)) / TILE_SIZE;
	if (map_x < 0 || map_x >= game->width_map || map_y < 0
		|| map_y >= game->heigth_map)
		return (0);
	if (game->true_game_map[map_y][map_x] == '1'
		|| game->true_game_map[map_y][map_x] == ' ')
		return (0);
	return (1);
}

