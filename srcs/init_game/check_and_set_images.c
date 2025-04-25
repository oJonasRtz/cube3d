/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set_images.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:54:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/25 18:06:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_and_set_images(t_game *game)
{
	int	width;
	int	heigth;

	game->no_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
		game->no_texture, &width, &heigth);
	if (!game->no_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->so_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
		game->so_texture, &width, &heigth);
	if (!game->so_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->we_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
		game->we_texture, &width, &heigth);
	if (!game->we_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->ea_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
		game->ea_texture, &width, &heigth);
	if (!game->ea_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	return (1);
}
