/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/09/03 20:06:54 by asergina         ###   ########.fr       */
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
	char	**envp_path;
	char	*path;
	char	*cmd_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	envp_path = ft_split(envp[i] + 5, ':');
	if (!envp_path)
		return (NULL);
	i = 0;
	while(envp_path[i])
	{
		path = ft_strjoin(envp_path[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		if (!cmd_path)
			return (free(path), NULL);		
		free(path);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	// free envp_path ?
	return (NULL); //wrong command from argv
}

void	execute(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	if (!cmd_arg)
		return ;
	cmd_path = parsing(cmd_arg[0], envp);
	if (!cmd_path)
	{
		perror("command not found");
		exit(127);
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
		return ;
	// free cmd_arg and cmd_path 
}

int	spaces_check(char *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != ' ' && cmd[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

void	child_process(int infile, char *cmd, int *fd, char **envp)
{
	if (dup2(infile, 0) == -1)
		return ;
	if (dup2(fd[1], 1) == -1)
		return ;
	close(fd[0]);
	close(infile);
	execute(cmd, envp);
}

void parent_process(int outfile, char *cmd, int *fd, char **envp)
{
	if (dup2(outfile, 1) == -1)
		return;

	if (dup2(fd[0], 0) == -1)
		return ;
	close(fd[1]);
	close(outfile);
	execute(cmd, envp);
}

void	pipex(int infile, int outfile, char *cmd1, char *cmd2, char **envp)
{
	int	fd[2];
	pid_t	process_id;

	if (pipe(fd) == -1)
		return (perror("Fork: "));
	process_id = fork();
	if (process_id == -1)
		return;
	if (process_id == 0)
		child_process(infile, cmd1, fd, envp);
	else
	{
		// wait
		parent_process(outfile, cmd2, fd, envp);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	if (argc == 5)
	{
		int infile = open(argv[1], O_RDONLY);
		int outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644 );
		if (infile < 0 || outfile < 0)
			return (perror("File: "), -1);
		if (!spaces_check(argv[2]) || !spaces_check(argv[3]))
			return (write(1, "Error\n", 6), -1);
		pipex(infile, outfile, argv[2], argv[3], envp);
		//execute(argv[2], envp);		
		printf ("finish");
	}
	else 
		return (write(1, "Error\n", 6), -1);
	return (0);
}
