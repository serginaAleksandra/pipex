/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/08/28 16:45:47 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*parsing(char *cmd, char **envp)
{
	int	i;
	char	*path_envp;
	char	**pathes;
	char	*path;
	char	*cmd_path;

	i = 0;
	path_envp = NULL;
	while (envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_envp = envp[i] + 5;
			break;
		}
		i++;
	}
	if (!path_envp)
		return (NULL);
	pathes = ft_split(path_envp, ':');
	if (!pathes)
		return (NULL);
	i = 0;
	while(pathes[i])
	{
		path = ft_strjoin(pathes[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		if (!cmd_path)
			return (NULL);
		free(path);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path); // ?
		i++;
	}
	return (NULL); //wrong command from argv
}

void	execute(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_argv;

	cmd_argv = ft_split(cmd, ' ');
	if (!cmd_argv)
		return ;
	cmd_path = parsing(cmd_argv[0], envp);
	if (!cmd_path)
	{
		perror("command not found");
		exit(127);
	}
	execve(cmd_path, cmd_argv, envp);
}
/*
void	pipex()
{
	int	fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return;
	if (pid == 0)
		//child process
	else
		//parent process
}*/

int	main(int argc, char *argv[], char **envp)
{
	if (argc == 5)
	{
		int infile = open(argv[1], O_RDONLY);
		int outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644 );
		if (infile < 0 || outfile < 0)
			return (-1);
		execute(argv[2], envp);		
		printf ("finish");
	}
	else 
		return (write(1, "Error\n", 6));
	return (0);
}
