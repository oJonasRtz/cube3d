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
#include <sys/time.h>

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

/*
	Note:
		usleep is not explicitly allowed by the subject, but it is a common way to implement frame rate control in C.
		if you wanna avoid using usleep, you can implement a busy-wait loop that checks the elapsed time until it reaches the desired frame duration.
		or just remove it you're gonna use more CPU, but it'll work.
*/
void	fps_control(t_game *game, int fps)
{
	static double	last_time = 0;
	double			current_time;
	double			elapsed;

	current_time = get_time();
	elapsed = current_time - last_time;

	while (elapsed < (1.0 / fps))
	{
		usleep(1000);
		current_time = get_time();
		elapsed = current_time - last_time;
	}

	last_time = current_time;
	render_the_3d(game);
}
