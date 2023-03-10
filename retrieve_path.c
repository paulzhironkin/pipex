/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:13:56 by latahbah          #+#    #+#             */
/*   Updated: 2022/02/12 20:02:40 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**retrieve_path(char **envp)
{
	char	*target;
	char	*paths;
	char	**splited_paths;
	int		i;

	i = 0;
	paths = NULL;
	target = "PATH";
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], target, 4))
			paths = envp[i];
		i++;
	}
	if (paths == NULL)
	{
		return (NULL);
	}
	paths = ft_substr(paths, 5, ft_strlen(paths) - 5);
	splited_paths = ft_split(paths, ':');
	free(paths);
	return (splited_paths);
}
