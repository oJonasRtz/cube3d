/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:40:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/30 18:49:59 by fruan-ba         ###   ########.fr       */
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
	double	next_x;
	double	next_y;

	next_x = game->player_x + game->rays.dirX * MOVE_SPEED;
	next_y = game->player_y + game->rays.dirY * MOVE_SPEED;
	if (can_move(game, next_x, game->player_y))
		game->player_x = next_x;
	if (can_move(game, game->player_x, next_y))
		game->player_y = next_y;
}

void	move_s(t_game *game)
{
	double	next_x;
	double	next_y;

	next_x = game->player_x - game->rays.dirX * MOVE_SPEED;
	next_y = game->player_y - game->rays.dirY * MOVE_SPEED;
	if (can_move(game, next_x, game->player_y))
		game->player_x = next_x;
	if (can_move(game, game->player_x, next_y))
		game->player_y = next_y;
}

void	move_d(t_game *game)
{
	double	next_x;
	double	next_y;

	next_x = game->player_x + game->rays.planeX * MOVE_SPEED;
	next_y = game->player_y + game->rays.planeY * MOVE_SPEED;
	if (can_move(game, next_x, game->player_y))
		game->player_x = next_x;
	if (can_move(game, game->player_x, next_y))
		game->player_y = next_y;
}

void	move_a(t_game *game)
{
	double	next_x;
	double	next_y;

	next_x = game->player_x - game->rays.planeX * MOVE_SPEED;
	next_y = game->player_y - game->rays.planeY * MOVE_SPEED;
	if (can_move(game, next_x, game->player_y))
		game->player_x = next_x;
	if (can_move(game, game->player_x, next_y))
		game->player_y = next_y;
}
