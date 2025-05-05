/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:19:35 by jonas             #+#    #+#             */
/*   Updated: 2025/05/05 15:31:58 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_x(t_dda *dda)
{
	int	temp;

	temp = (int)(dda->raydirx * TILE_SIZE);
	if ((dda->side == 0 && dda->raydirx > 0) || (dda->side == 1 && dda->raydirx < 0))
        temp = TILE_SIZE - temp - 1;
	return (temp);
}

static int	get_tex_y(t_dda *dda, int y)
{
	int	temp;

	temp = (int)(y * TILE_SIZE / dda->lineheight) & (TILE_SIZE - 1);
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
    tex_y = get_tex_y(&game->dda, y);
    colour = get_colour(game, tex_x, tex_y);
    return (colour);
}
