/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:21:48 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/23 14:24:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_no_event(void)
{
	return (0);
}

static int	handle_input(int key, t_game *game)
{
	int	max_offset_x;
	int	max_offset_y;

	max_offset_x = (game->width * TILE_SIZE) - game->width;
	max_offset_y = (game->heigth * TILE_SIZE) - game->heigth;
	if (key == 65307)
		destroy(game);
	if (key == 65361)
		game->offset_x -= TILE_SIZE;
	if (key == 65362)
		game->offset_y -= TILE_SIZE;
	if (key == 65363)
		game->offset_x += TILE_SIZE;
	if (key == 65364)
		game->offset_y += TILE_SIZE;
	if (game->offset_x > max_offset_x || game->offset_y > max_offset_y)
		return (1);
	minimap(game);
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
	minimap(game);
	mlx_loop(game->mlx.mlx_ptr);
}
