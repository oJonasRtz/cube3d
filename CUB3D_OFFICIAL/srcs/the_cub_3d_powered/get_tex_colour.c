/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:19:35 by jonas             #+#    #+#             */
/*   Updated: 2025/05/05 16:06:53 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_x(t_dda *dda)
{
	int		tex_x;
	double	wall_x;

	if (dda->side == 0)
		wall_x = dda->py + dda->perpwalldist * dda->raydiry;
	else
		wall_x = dda->px + dda->perpwalldist * dda->raydirx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * TILE_SIZE);
	if ((dda->side == 0 && dda->raydirx > 0) || (dda->side == 1 && dda->raydirx < 0))
		tex_x = TILE_SIZE - tex_x - 1;
	return (tex_x);
}

static int	get_tex_y(t_dda *dda, t_game *game, int y)
{
	int	temp;
	int	draw_start;

	draw_start = -dda->lineheight / 2 + game->screen_h / 2;
	if (draw_start < 0)
		draw_start = 0;
	temp = ((y - draw_start) * TILE_SIZE) / dda->lineheight;
	if (temp < 0)
		temp = 0;
	if (temp >= TILE_SIZE)
		temp = TILE_SIZE - 1;
	return (temp);
}

static int	get_colour(t_game *game, int tex_x, int tex_y)
{
	return (*(int *)(game->no_addr + tex_y * game->line_length_no + tex_x * (game->bpp_no / 8)));
}

int get_tex_colour(t_game *game, int y)
{
    int	tex_x;
    int	tex_y;
    int	colour;

	if (!game->no_addr)
		return (COLOUR_DEFAULT);
	tex_x = get_tex_x(&game->dda);
    tex_y = get_tex_y(&game->dda, game, y);
    colour = get_colour(game, tex_x, tex_y);
    return (colour);
}
