/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/02 15:59:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda_loop(t_game *game)
{
	while (game->dda.hit == 0)
	{
		if (game->dda.sideDistX < game->dda.sideDistY)
		{
			game->dda.sideDistX += game->dda.deltaDistX;
			game->dda.mapX += game->dda.stepX;
			game->dda.side = 0;
		}
		else
		{
			game->dda.sideDistY += game->dda.deltaDistY;
			game->dda.mapY += game->dda.stepY;
			game->dda.side = 1;
		}
		if (game->dda.mapX < 0
			|| game->dda.mapX >= game->width_map
			|| game->dda.mapY < 0
			|| game->dda.mapY >= game->heigth_map)
		{
			game->dda.hit = 1;
			break ;
		}
		if (game->true_game_map[game->dda.mapY][game->dda.mapX] == '1')
			game->dda.hit = 1;
	}
}
