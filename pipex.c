/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/08/29 18:51:58 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

char	*parsing(char *cmd, char **envp)
{
	int	i;
	char	**envp_pathes;
	char	*path;
	char	*cmd_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
	{
		i++;
	}
	envp_pathes = ft_split(envp[i] + 5, ':');
	if (!envp_pathes)
		return (NULL);
	i = 0;
	while(envp_pathes[i])
	{
		path = ft_strjoin(envp_pathes[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		if (!cmd_path)
			return (NULL);		
		free(path);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
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
