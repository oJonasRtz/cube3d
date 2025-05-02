/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:36:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/01 21:36:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_dir(t_game *game, double rot_angle)
{
	double	old_dir_x;
	double	old_p;

	game->angle += rot_angle;
	old_dir_x = game->rays.dirX;
	game->rays.dirX = old_dir_x * cos(rot_angle) - game->rays.dirY * sin(rot_angle);
	game->rays.dirY = old_dir_x * sin(rot_angle) + game->rays.dirY * cos(rot_angle);
	old_p = game->rays.planeX;
	game->rays.planeX = old_p * cos(rot_angle) - game->rays.planeY * sin(rot_angle);
	game->rays.planeY = old_p * sin(rot_angle) + game->rays.planeY * cos(rot_angle);
	update_offset(game);
}
