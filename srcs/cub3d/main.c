/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:29:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:02:20 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (ft_putendl_fd_1("How to use: ./cub3d <map.cub>", 2));
	if (!check_cub(argv[1]))
		return (ft_putendl_fd_1("Directory/Empty file/.cub Error", 2));
	if (!init_game(argv[1], &game))
	{
		destroy(&game);
		return (ft_putendl_fd_1("Init Error", 2));
	}
	show_textures(&game);
	run_window(&game);
	return (destroy(&game));
}
