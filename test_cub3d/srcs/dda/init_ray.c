/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:03:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/30 12:33:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / game->width - 1.0;
	game->dda.rayDirX = game->rays.dirX + game->rays.planeX * camera_x;
	game->dda.rayDirY = game->rays.dirY + game->rays.planeY * camera_x;
}
