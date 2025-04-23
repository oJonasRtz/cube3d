/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:21:48 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/23 15:51:50 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_no_event(void)
{
	return (0);
}

static int	handle_input(int key, t_game *game)
{
	if (key == 65307)
		destroy(game);
	// if (key == 65361)
	// 	game->offset_x -= TILE_SIZE;
	// if (key == 65362)
	// 	game->offset_y -= TILE_SIZE;
	// if (key == 65363)
	// 	game->offset_x += TILE_SIZE;
	// if (key == 65364)
	// 	game->offset_y += TILE_SIZE;
	// mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win);
	// game->min_row = game->offset_y / TILE_SIZE;
	// game->min_col = game->offset_x / TILE_SIZE;
	// minimap(game);
	return (0);
}

void	run_window(t_game *game)
{
	if (!game)
		return ;
	mlx_loop_hook(game->mlx.mlx_ptr, &handle_no_event, NULL);
	mlx_key_hook(game->mlx.win, &handle_input, game);
	mlx_hook(game->mlx.win, 17, 0, &destroy, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, &handle_input, game);
	// minimap(game);
	mlx_loop(game->mlx.mlx_ptr);
}
