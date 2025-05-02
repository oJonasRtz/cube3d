/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:06:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/01 21:06:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_dir(t_game *game, double angle)
{
	(void)angle;
	double	next_x;
	double	next_y;
	double	central;

	central = atan2(game->rays.dirY, game->rays.dirX);
	next_x = game->player_x + cos(central) * MOVE_SPEED;
	next_y = game->player_y + sin(central) * MOVE_SPEED;

	if (can_move(game, next_x, game->player_y))
		game->player_x = next_x;
	if (can_move(game, game->player_x, next_y))
		game->player_y = next_y;
	update_offset(game);
}
