/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:21:48 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/29 12:10:47 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_keys	*get_keys(void)
{
	static t_keys	keys[5] = 
	{
		{119, &move_w},
		{97, &move_a},
		{115, &move_s},
		{100, &move_d}
	};
	return (keys);
}

static int	handle_no_event(t_game *game)
{
	game->min_row = game->offset_y / TILE_SIZE;
	game->min_col = game->offset_x / TILE_SIZE;
	render_the_3d(game);
	return (0);
}

static int	handle_input(int key, t_game *game)
{
	t_keys	*keys;
	int		i;
	
	if (key == 65307)
		destroy(game);
	if (key == 65361 || key == 65363)
		update_angle_dir_x_y(game, key);
	keys = get_keys();
	i = -1;
	while (++i < 4)
		if (key == keys[i].key)
			keys[i].f(game);
	// minimap(game);
	return (0);
}

void	run_window(t_game *game)
{
	if (!game)
		return ;
	mlx_get_screen_size(game->mlx.mlx_ptr, &game->screen_w, &game->screen_h);
	ft_printf("Screen Width: %d\n", game->screen_w);
	ft_printf("Screen Heigth: %d\n", game->screen_h);
	if (game->width > game->screen_w)
		game->width = game->screen_w;
	if (game->heigth > game->screen_h)
		game->heigth = game->screen_h;
	mlx_loop_hook(game->mlx.mlx_ptr, &handle_no_event, game);
	mlx_hook(game->mlx.win, 17, 0, &destroy, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, &handle_input, game);
	// minimap(game);
	render_the_3d(game);
	mlx_loop(game->mlx.mlx_ptr);
	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win);
}
