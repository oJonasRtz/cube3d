/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:42:49 by jonas             #+#    #+#             */
/*   Updated: 2025/05/07 14:46:49 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_struct(t_mouse *mouse, int x, int y)
{
	if (!mouse)
		return ;
	mouse->prev_x = mouse->x;
	mouse->prev_y = mouse->y;
	mouse->x = x;
	mouse->y = y;
}

static double	set_sensability(t_mouse *mouse)
{
	return ((mouse->x - mouse->prev_x) * 0.01);
}

void	update_angle_mouse(t_game *game, t_mouse *mouse)
{
	game->angle += set_sensability(mouse);
	if (game->angle < 0)
		game->angle += 2 * M_PI;
	if (game->angle >= 2 * M_PI)
		game->angle -= 2 * M_PI;
	game->dir_x = cos(game->angle);
	game->dir_y = sin(game->angle);
	get_plane_x_y(game);
}

void	draw_mouse_target(t_game *game)
{
	t_mlx	*mlx;

	if (!game->target)
		return ;
	mlx = &game->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		game->target, game->width / 2, game->heigth / 2);
}
