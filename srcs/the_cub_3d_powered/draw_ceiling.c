/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:17:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/29 12:03:31 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling(t_game *game, int x)
{
	int	colour;
	int	y;
	int	end;
	int	max_y;

	end = game->draw_3d_center_s - 1;
	max_y = game->heigth - 1;
	if (end < 0)
		return ;
	if (end > max_y)
		end = max_y;
	y = 0;
	colour = ft_atoi_base(game->rrggbb_ceiling + 2, 16);
	while (y <= end)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			x, y, colour);
		y++;
	}
}
