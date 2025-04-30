/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:58:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 19:23:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_all_3d(t_game *game)
{
	double	proj_plane_dist;
	double	perp_dist;
	int	start;
	int	end;
	double	raw_h;

	proj_plane_dist = (game->width / 2.0 / tan(VISUAL_CAMP / 2.0));
	perp_dist = fmax(game->distance_x, 0.0001);
	raw_h = (TILE_SIZE / perp_dist) * proj_plane_dist;
	start = (int)floor(game->heigth / 2.0 - raw_h / 2.0);
	end = (int)ceil(game->heigth / 2.0 + raw_h / 2.0) - 1;
	if (start < 0)
		start = 0;
	if (end > game->heigth - 1)
		end = game->heigth - 1;
	game->draw_3d_center_s = start;
	game->draw_3d_center_e = end;
}
