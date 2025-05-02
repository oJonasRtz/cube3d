/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_perp_dist_update_wall.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:47:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/02 16:02:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_perp_dist_update_wall(t_game *game, double px, double py)
{
	double	perp_dist;

	px = px / TILE_SIZE;
	py = py / TILE_SIZE;
	if (game->dda.side == 0)
	{
		perp_dist = ((game->dda.mapX - px) + (1 - game->dda.stepX) / 2.0)
			/ game->dda.rayDirX;
	}
	else
	{
		perp_dist = ((game->dda.mapY - py) + (1 - game->dda.stepY) / 2.0)
			/ game->dda.rayDirY;
	}
	if (perp_dist <= 0.0)
		perp_dist = 0.0001;
	game->dda.lineHeight = (int)(game->heigth / perp_dist);
	game->dda.drawStart = -game->dda.lineHeight / 2 + game->heigth / 2;
	if (game->dda.drawStart < 0)
		game->dda.drawStart = 0;
	game->dda.drawEnd = game->dda.lineHeight / 2 + game->heigth / 2;
	if (game->dda.drawEnd >= game->heigth)
		game->dda.drawEnd = game->heigth - 1;
}
