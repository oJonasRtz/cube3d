/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:19:35 by jonas             #+#    #+#             */
/*   Updated: 2025/05/05 15:21:17 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_tex_colour(t_game *game, int y)
{
    int tex_x;
    int tex_y;
    int colour;

	if (!game->no_addr)
		return (COLOUR_DEFAULT);
    // Calcula tex_x com base na direção do raio
    tex_x = (int)(game->dda.raydirx * TILE_SIZE);
    if ((game->dda.side == 0 && game->dda.raydirx > 0) || (game->dda.side == 1 && game->dda.raydirx < 0))
        tex_x = TILE_SIZE - tex_x - 1;

    // Calcula tex_y com base na altura da linha
    tex_y = (int)(y * TILE_SIZE / game->dda.lineheight) & (TILE_SIZE - 1); // usando módulo para garantir que tex_y esteja dentro dos limites da textura

    // Acessa a textura corretamente
    colour = *(int *)(game->no_addr + tex_y * game->line_length_no + tex_x * (game->bpp_no / 8));
    
    return colour;
}
