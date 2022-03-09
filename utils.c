/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:08:31 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/26 16:40:24 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

int	access_file(char *file1)
{
	if (access(file1, F_OK) == -1 || access(file1, R_OK) == -1)
	{
		perror("Error");
		return (0);
	}
	return (1);
}

char	*ft_access(char **paths, char *cmd)
{
	int		i;
	char	*path0;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path0 = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path0, cmd);
		free(path0);
		if (!access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	return (0);
}

char	*path_to_cmd(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
	{
		i++;
		if (!env[i])
		{
			perror("Error");
			exit(1);
		}
	}
	paths = ft_split(env[i] + 5, ':');
	path = ft_access(paths, cmd);
	//ft_free(paths);
	return (path);
}

void	ft_command(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = path_to_cmd(cmd[0], env);
	while(1);
	if (execve(path, cmd, env) == -1)
	{
		perror("Error");
		exit(1);
	}
}
