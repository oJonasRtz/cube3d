/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_things.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:54:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 15:29:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_more_things(t_game *game)
{
	game->offset_x = 0;
	game->offset_y = 0;
	game->min_col = 0;
	game->min_row = 0;
	game->max_col = 0;
	game->min_col = 0;
}

void	init_all_things(t_game *game)
{
	game->mlx.mlx_ptr = NULL;
	game->mlx.win = NULL;
	game->players = 0;
	game->invalid_map = 0;
	game->width = -1;
	game->heigth = -1;
	game->rrggbb_floor = NULL;
	game->rrggbb_ceiling = NULL;
	game->maps = NULL;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_colours = NULL;
	game->ceiling_colours = NULL;
	game->true_game_map = NULL;
	game->no_texture_index = 0;
	game->so_texture_index = 0;
	game->we_texture_index = 0;
	game->ea_texture_index = 0;
	game->floor_colours_index = 0;
	game->ceiling_colours_index = 0;
	set_more_things(game);
}
