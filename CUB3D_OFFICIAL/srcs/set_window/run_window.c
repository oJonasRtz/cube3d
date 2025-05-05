/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:21:48 by jopereir          #+#    #+#             */
/*   Updated: 2025/05/05 20:40:18 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_key_release(int keycode)
{
	if (get_handle_key(0, 0) == keycode)
		get_handle_key(0, 1);
	return (0);
}

static int	handle_no_event(t_game *game)
{
	int		key;
	t_keys	*keys;
	int		i;

	key = get_handle_key(0, 0);
	game->min_row = game->offset_y / TILE_SIZE;
	game->min_col = game->offset_x / TILE_SIZE;
	render_the_3d(game);
	keys = get_keys();
	i = -1;
	while (++i < 4)
		if (key == keys[i].key)
			keys[i].f(game);
	return (0);
}

static int	handle_input(int key, t_game *game)
{
	int	pitch_max;
	int	pitch_min;

	pitch_max = (game->heigth / 2) - 1;
	pitch_min = (-game->heigth / 2) - 1;
	if (key == 65307)
		destroy(game);
	if (key == 65361 || key == 65363)
		update_angle_dir_x_y(game, key);
	if (key == 65362)
	{
		game->pitch += PITCH_STEP;
		if (game->pitch > pitch_max)
			game->pitch = pitch_max;
	}
	if (key == 65364)
	{
		game->pitch -= PITCH_STEP;
		if (game->pitch < pitch_min)
			game->pitch = pitch_min;
	}
	get_handle_key(key, 1);
	return (0);
}

static int	handle_mouse(int x, int y, t_game *game)
{
	int		code;
	t_mouse	*mouse;

	mouse = &game->mouse;
	mouse->prev_x = mouse->x;
	mouse->prev_y = mouse->y;
	mouse->x = x;
	mouse->y = y;
	code = 65361;
	if (mouse->x > mouse->prev_x)
		code = 65363;
	update_angle_dir_x_y(game, code);
	return (0);
}

void	run_window(t_game *game)
{
	if (!game)
		return ;
	ft_printf("Screen Width: %d\n", game->screen_w);
	ft_printf("Screen Heigth: %d\n", game->screen_h);
	if (game->width > game->screen_w)
		game->width = game->screen_w;
	if (game->heigth > game->screen_h)
		game->heigth = game->screen_h;
	mlx_loop_hook(game->mlx.mlx_ptr, &handle_no_event, game);
	mlx_hook(game->mlx.win, 17, 0, &destroy, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, &handle_input, game);
	mlx_hook(game->mlx.win, 3, 1L << 1, &handle_key_release, NULL);
	mlx_hook(game->mlx.win, 6, 1L << 6, &handle_mouse, game);
	mlx_loop(game->mlx.mlx_ptr);
}
