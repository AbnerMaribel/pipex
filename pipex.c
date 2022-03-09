/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:58:06 by amaribel          #+#    #+#             */
/*   Updated: 2022/02/21 22:54:36 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **env, int *fd)
{
	int	f;

	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		perror("Error");
		exit(1);
	}
	if (dup2(fd[1], 1) == -1 || dup2(f, 0) == -1)
	{
		perror("Error");
		exit(1);
	}
	if (close(fd[0]) == -1 || close(fd[1]) == -1 || close(f) == -1)
	{
		perror("Error");
		exit(1);
	}
	ft_command(argv[2], env);
}

void	parent_process(char **argv, char **env, int *fd)
{
	int	f;

	f = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (f == -1)
	{
		perror("Error");
		exit(1);
	}
	if (dup2(fd[0], 0) == -1 || dup2(f, 1) == -1)
	{
		perror("Error");
		exit(1);
	}
	if (close(fd[1]) == -1 || close(fd[0]) == -1 || close(f) == -1)
	{
		perror("Error");
		exit(1);
	}
	ft_command(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	id;
	int		fd[2];

	if (argc == 5 && access_file(argv[1]))
	{
		if (pipe(fd) == -1)
		{
			perror("Error");
			exit(1);
		}
		id = fork();
		if (id == -1)
		{
			perror("Error");
			exit(1);
		}
		if (id == 0)
			child_process(argv, env, fd);
		parent_process(argv, env, fd);
	}
}
