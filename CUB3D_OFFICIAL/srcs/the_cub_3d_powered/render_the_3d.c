/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:09:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/07 16:05:20 by jonas            ###   ########.fr       */
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

static int	aplly_shadow(int colour, int side)
{
	if (side == 1)
		return ((colour >> 1) & 0x7F7F7F);
	return (colour);
}

inline void	put_pixel(t_tex *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->addr)
		return ;
	if (x < 0 || y < 0)
		return ;
	if (x >= img->linelen || y >= img->linelen)
		return ;

	dst = img->addr + (y * img->linelen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_column(t_game *game, int x)
{
	int		y;
	int		color;

	y = game->draw_3d_center_s;
	while (y < game->draw_3d_center_e)
	{
		color = get_tex_colour(game, y);
		color = aplly_shadow(color, game->dda.side);
		put_pixel(&game->frame, x, y, color);
		y++;
	}
}

static int	init_framebuffer(t_game *game)
{
	if (game->frame.img)
		return (1);

	game->frame.img = mlx_new_image(game->mlx.mlx_ptr,
		game->width, game->heigth);

	if (!game->frame.img)
		return (0);

	game->frame.addr = mlx_get_data_addr(
		game->frame.img,
		&game->frame.bpp,
		&game->frame.linelen,
		&game->frame.endian
	);

	if (!game->frame.addr)
		return (0);

	return (1);
}

void	render_the_3d(t_game *game)
{
	int			x;
	double		px;
	double		py;

	if (!init_framebuffer(game))
		return ;

	// clear BEFORE rendering
	ft_memset(game->frame.addr, 0,
		game->frame.linelen * game->heigth);

	init_camera_plane(game);

	x = 0;
	while (x < game->width)
	{
		new_position_px_py(game, &px, &py);
		init_ray(game, x);
		init_dda_params(game, px, py);
		dda_loop(game);
		calculate_perp_dist_update_wall(game, px, py);

		game->draw_3d_center_s = game->dda.drawstart + game->pitch;
		game->draw_3d_center_e = game->dda.drawend + game->pitch;

		draw_ceiling(game, x);
		draw_column(game, x);
		draw_floor(game, x);
		x++;
	}

	mlx_put_image_to_window(game->mlx.mlx_ptr,
		game->mlx.win,
		game->frame.img,
		0, 0);

	draw_mouse_target(&game->mlx, &game->mouse,
		game->width, game->heigth);
}
