/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_things.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:54:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 16:48:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_all_things(t_game *game)
{
	game->players = 0;
	game->invalid_map = 0;
	game->mlx = NULL;
	game->maps = NULL;
	game->win = NULL;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_colours = NULL;
	game->ceiling_colours = NULL;
	game->true_game_map = NULL;
	game->mlx = NULL;
	game->win = NULL;
}
