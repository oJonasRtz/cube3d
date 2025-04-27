/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:17:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/26 21:17:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < game->draw_3d_center_s)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			400 + x, 400 + y, 0xffff00);
		y++;
	}
}
