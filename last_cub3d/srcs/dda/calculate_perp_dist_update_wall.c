/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_perp_dist_update_wall.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:47:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/30 16:58:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	calculate_perp_dist_update_wall(t_game *game)
{
	double	px;
	double	py;
	double	perpDist;

	px = game->player_x;
	py = game->player_y;
	if (game->dda.side == 0)
	{
		perpDist = ((game->dda.mapX - px) + (1 - game->dda.stepX) / 2.0)
			/ game->dda.rayDirX;
	}
	else
	{
		perpDist = ((game->dda.mapY - py) + (1 - game->dda.stepY) / 2.0)
			/ game->dda.rayDirY;
	}
	game->dda.lineHeight = (int)(game->heigth / perpDist);
	game->dda.drawStart = -game->dda.lineHeight / 2 + game->heigth / 2;
	if (game->dda.drawStart < 0)
		game->dda.drawStart = 0;
	game->dda.drawEnd = game->dda.lineHeight / 2 + game->heigth / 2;
	if (game->dda.drawEnd >= game->heigth)
		game->dda.drawEnd = game->heigth - 1;
	return (perpDist);
}
