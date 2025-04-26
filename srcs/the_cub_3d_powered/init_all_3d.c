/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:58:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/26 13:14:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_all_3d(t_game *game)
{
	game->center_win = game->heigth / 2;
	if (game->distance > 0)
	{
		game->wall_3d_height = (TILE_SIZE * game->heigth) / (int)game->distance;
		game->wall_3d_width = (TILE_SIZE * game->width) / (int)game->distance;
		game->draw_3d_center_s = game->center_win - (game->wall_3d_height / 2);
		game->draw_3d_center_e = game->center_win + (game->wall_3d_height / 2);
	}
	else
	{
		game->wall_3d_height = 0;
		game->wall_3d_width = 0;
		game->draw_3d_center_s = 0;
		game->draw_3d_center_e = 0;
	}
}
