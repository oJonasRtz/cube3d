/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:00:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 11:11:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	execute_command(char *cmd, char **envp)
{
	char	*paths_temp;
	char	**paths;
	char	*path;
	int		index;
	char	**commands;

	index = 0;
	while ((!ft_strnstr(envp[index], "PATH", 4) && envp[index]))
		index++;
	paths_temp = ft_strdup(envp[index] + 5);
	if (!paths_temp)
		return (1);
	paths = ft_split(paths_temp, ':');
	if (!paths)
		return (free_splits(paths_temp, NULL, NULL, NULL));
	commands = ft_split(cmd, ' ');
	if (!commands)
		return (free_splits(paths_temp, paths, NULL, NULL));
	path = find_path(commands[0], paths);
	if (!path)
		return (free_splits(paths_temp, paths, commands, NULL));
	if (execve(path, commands, NULL) == -1)
		free(path);
	exit(free_splits(paths_temp, paths, commands, NULL));
	return (1);
}
