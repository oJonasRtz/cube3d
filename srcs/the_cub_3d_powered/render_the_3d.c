/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:09:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/26 13:16:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_the_3d(t_game *game)
{
	int	y;

	y = game->draw_3d_center_s;
	while (y < game->draw_3d_center_e)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			game->width / 2, y, COLOUR_DEFAULT);
		y++;
	}
}
