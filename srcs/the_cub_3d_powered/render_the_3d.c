/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:09:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/26 19:49:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	new_position_px_py(t_game *g, double *px, double *py)
{
	*px = (g->width / 2) + g->offset_x;
	*py = (g->heigth / 2) + g->offset_y;
	g->px_start = *px;
	g->py_start = *py;
	g->dir_get_x = cos(g->angle_k);
	g->dir_get_y = sin(g->angle_k);
}

static void	get_radius(t_game *game)
{
	double	px;
	int		map_x;
	int		map_y;
	double	py;

	new_position_px_py(game, &px, &py);
	while (1)
	{
		map_x = px / TILE_SIZE;
		map_y = py / TILE_SIZE;
		if (px < 0 || py < 0 || map_y >= game->heigth_map
			|| map_x >= (int)ft_strlen(game->true_game_map[map_y]))
			break ;
		if (game->true_game_map[map_y][map_x] == '1'
			|| game->true_game_map[map_y][map_x] == ' ')
			break ;
		px += game->dir_get_x;
		py += game->dir_get_y;
	}
	game->target_x = map_x;
	game->dir_x_c = px - game->px_start;
	game->dir_y_c = py - game->py_start;
	get_distance(game, 4);
}

static void	draw_column(t_game *game, int x)
{
	int	y;

	init_all_3d(game);
	y = game->draw_3d_center_s;
	while (y < game->draw_3d_center_e)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			400 + x, 400 + y, COLOUR_DEFAULT);
		y++;
	}
}

void	render_the_3d(t_game *game)
{
	int	x;

	game->angle_k = game->angle_left;
	x = 0;
	while (game->angle_k <= game->angle_right && x < game->width)
	{
		get_radius(game);
		draw_column(game, x);
		game->angle_k += (game->angle_right - game->angle_left) / game->width;
		x++;
	}
}
