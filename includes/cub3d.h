/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:31:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 10:25:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "structs.h"
# include "validation.h"
# include "window.h"

# define COLOUR_FLOOR 0xff0000
# define COLOUR_WALL 0x00ff00
# define COLOUR_PLAYER 0x0000ff

int	destroy(t_game *game);
int	get_width_heigth(t_game *game);

#endif /* CUB3D_H */
