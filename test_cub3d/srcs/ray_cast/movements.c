/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:40:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/01 14:30:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_offset(t_game *game)
{
	game->offset_x = game->player_x * TILE_SIZE - (game->width  / 2.0);
	game->offset_y = game->player_y * TILE_SIZE - (game->heigth / 2.0);
}

void	move_w(t_game *game)
{
	move_dir(game, game->angle);
}

void	move_s(t_game *game)
{
	move_dir(game, game->angle + M_PI);
}

void	move_d(t_game *game)
{
	move_dir(game, game->angle + M_PI / 2);
}

void	move_a(t_game *game)
{
	move_dir(game, game->angle - M_PI / 2);
}
