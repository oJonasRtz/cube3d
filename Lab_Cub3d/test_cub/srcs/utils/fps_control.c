/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:46:00 by jonas             #+#    #+#             */
/*   Updated: 2025/05/07 23:05:20 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

// void	fps_control(t_game *game)
// {
// 	static int	frame_skip = 0;

// 	if (frame_skip++ < 5)
// 		return ;
// 	frame_skip = 0;
// 	render_the_3d(game);
// }

void fps_control(t_game *game, int fps) {
	static clock_t last_time = 0;
	clock_t current_time;
	double elapsed_time;

	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC;
	if (elapsed_time < 1.0 / fps)
		return;

	last_time = current_time;
	render_the_3d(game);
}