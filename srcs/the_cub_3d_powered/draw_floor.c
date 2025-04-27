/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:16:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 10:36:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_floor(t_game *game, int x)
{
	int	colour;
	int	y;

	colour = ft_atoi_base(game->rrggbb_floor + 2, 16);
	y = game->draw_3d_center_e;
	while (y < game->heigth)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			400 + x, 400 + y, colour);
		y++;
	}
}
