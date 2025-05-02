/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:35:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/30 17:44:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_camera_plane(t_game *game)
{
	game->rays.dirX = cos(game->angle);
	game->rays.dirY = sin(game->angle);
	game->rays.planeX = -game->rays.dirY * VISUAL_CAMP;
	game->rays.planeY = game->rays.dirX * VISUAL_CAMP;
}
