/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:16:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/29 12:03:42 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_floor(t_game *game, int x)
{
	int	colour;
	int	y;
	int	start;
	int	max_y;

	start = game->draw_3d_center_e + 1;
	max_y = game->heigth - 1;
	if (start > max_y)
		return ;
	if (start < 0)
		start = 0;
	colour = ft_atoi_base(game->rrggbb_floor + 2, 16);
	y = start;
	while (y <= max_y)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			x, y, colour);
		y++;
	}
}
