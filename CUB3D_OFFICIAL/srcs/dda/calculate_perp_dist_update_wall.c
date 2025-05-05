/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_perp_dist_update_wall.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:47:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/05 15:52:44 by jonas            ###   ########.fr       */
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
		perp_dist = ((game->dda.mapx - px) + (1 - game->dda.stepx) / 2.0)
			/ game->dda.raydirx;
	}
	else
	{
		perp_dist = ((game->dda.mapy - py) + (1 - game->dda.stepy) / 2.0)
			/ game->dda.raydiry;
	}
	if (perp_dist <= 0.0)
		perp_dist = 0.0001;
	game->dda.lineheight = (int)(game->heigth / perp_dist);
	game->dda.drawstart = -game->dda.lineheight / 2 + game->heigth / 2;
	if (game->dda.drawstart < 0)
		game->dda.drawstart = 0;
	game->dda.drawend = game->dda.lineheight / 2 + game->heigth / 2;
	if (game->dda.drawend >= game->heigth)
		game->dda.drawend = game->heigth - 1;
	game->dda.perpwalldist = perp_dist;
	game->dda.px = px;
	game->dda.py = py;
}
