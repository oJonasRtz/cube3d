/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_perp_dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:41:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/30 14:50:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	calculate_perp_dist(t_game *game)
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
	else if (game->dda.side == 1)
	{
		perpDist = ((game->dda.mapY - py) + (1 - game->dda.stepY) / 2.0)
			/ game->dda.rayDirY;
	}
	return (perpDist);
}
