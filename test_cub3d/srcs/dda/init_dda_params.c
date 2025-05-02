/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:48:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/30 14:30:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_sidedist(t_game *game, double px, double py)
{
	if (game->dda.stepX == -1)
	{
		game->dda.sideDistX = (px - game->dda.mapX)
			* game->dda.deltaDistX;
	}
	else
	{
		game->dda.sideDistX = (game->dda.mapX + 1.0 - px)
			* game->dda.deltaDistX;
	}
	if (game->dda.stepY == -1)
	{
		game->dda.sideDistY = (py - game->dda.mapY)
			* game->dda.deltaDistY;
	}
	else
	{
		game->dda.sideDistY = (game->dda.mapY + 1.0 - py)
			* game->dda.deltaDistY;
	}
}

void	init_dda_params(t_game *game, double px, double py)
{
	px = px / TILE_SIZE;
	py = py / TILE_SIZE;
	game->dda.mapX = (int)px;
	game->dda.mapY = (int)py;
	game->dda.deltaDistX = fabs(1.0 / game->dda.rayDirX);
	game->dda.deltaDistY = fabs(1.0 / game->dda.rayDirY);
	if (game->dda.rayDirX < 0)
		game->dda.stepX = -1;
	else
		game->dda.stepX = 1;
	if (game->dda.rayDirY < 0)
		game->dda.stepY = -1;
	else
		game->dda.stepY = 1;
	game->dda.hit = 0;
	calculate_sidedist(game, px, py);
}
