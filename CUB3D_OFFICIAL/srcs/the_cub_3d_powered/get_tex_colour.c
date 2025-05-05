/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:19:35 by jonas             #+#    #+#             */
/*   Updated: 2025/05/05 17:36:53 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_perpwalldist(t_dda *dda)
{
	if (dda->side == 0)
		return ((dda->mapx - dda->px + (1 - dda->stepx) / 2) / dda->raydirx);
	return ((dda->mapy - dda->py + (1 - dda->stepy) / 2) / dda->raydiry);
}

static int	get_tex_x(t_dda *dda)
{
	int		tex_x;
	double	wall_x;
	double	perpwalldist;

	perpwalldist = get_perpwalldist(dda);
	if (dda->side == 0)
		wall_x = dda->py + perpwalldist * dda->raydiry;
	else
		wall_x = dda->px + perpwalldist * dda->raydirx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * TILE_SIZE);
	if ((dda->side == 0 && dda->raydirx > 0) || (dda->side == 1 && dda->raydiry < 0))
		tex_x = TILE_SIZE - tex_x - 1;
	return (tex_x);
}

static int	get_tex_y(t_dda *dda, int screen_h, int pitch, int y)
{
	int	temp;
	int	draw_start;

	draw_start = -dda->lineheight / 2 + screen_h / 2 + pitch;
	if (draw_start < 0)
		draw_start = 0;
	temp = ((y - draw_start) * TILE_SIZE) / dda->lineheight;
	if (temp < 0)
		temp = 0;
	if (temp >= TILE_SIZE)
		temp = TILE_SIZE - 1;
	return (temp);
}

static int	get_colour(t_tex *tex, int tex_x, int tex_y)
{
	return (*(int *)(tex->addr + tex_y * tex->linelen + tex_x * (tex->bpp / 8)));
}

int get_tex_colour(t_game *game, int y)
{
    int	tex_x;
    int	tex_y;
    int	colour;

	tex_x = get_tex_x(&game->dda);
    tex_y = get_tex_y(&game->dda, game->screen_h, game->pitch, y);
    colour = get_colour(&game->ea, tex_x, tex_y);
    return (colour);
}
