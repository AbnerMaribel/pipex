/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:58:18 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/23 15:14:44 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	child_process(char **argv, char **env, int *fd);
void	parent_process(char **argv, char **env, int *fd);
int		access_file(char *file1);
char	*path_to_cmd(char *cmd, char **env);
void	ft_command(char *argv, char **env);
char	*ft_access(char **paths, char *cmd);
void	ft_free(char **ar);

#endif