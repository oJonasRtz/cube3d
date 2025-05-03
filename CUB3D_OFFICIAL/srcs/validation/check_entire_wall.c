/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entire_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:05:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/03 18:40:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_entire_wall(t_game *game, int index)
{
	int	count;

	count = 0;
	while (game->true_game_map[index][count] != '\n'
		&& game->true_game_map[index][count] != '\0')
	{
		if (game->true_game_map[index][count] != '1'
			&& game->true_game_map[index][count] != ' '
			&& game->true_game_map[index][count] != '\t')
			return (0);
		count++;
	}
	return (1);
}
