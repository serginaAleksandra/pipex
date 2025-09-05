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

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	*free_return(char **to_free, char *to_return)
{
	free_matrix(to_free);
	return (to_return);
}

void	exit_with_error(const char *msg, int code)
{
	perror(msg);
	exit(code);
}

int	spaces_check(char *cmd)
{
	if (!cmd)
		return (0);
	while (cmd)
	{
		if (*cmd != ' ' && *cmd != '\t')
			return (1);
		cmd++;
	}
	return (0);
}

char	*parsing(char *cmd, char **envp)
{
	int	i;
	char	**envp_path;
	char	*path;
	char	*cmd_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i] || !(envp_path = ft_split(envp[i] + 5, ':')))
		return (NULL);
	i = 0;
	while(envp_path[i])
	{
		if (!(path = ft_strjoin(envp_path[i], "/")))
			return (free_return(envp_path, NULL));
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (!cmd_path)
   			return (free_return(envp_path, NULL));
		if (access(cmd_path, X_OK) == 0)
			return (free_return(envp_path, cmd_path));
		free(cmd_path);
		i++;
	}
	return (free_return(envp_path, NULL));
}

void	execute(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	if (!cmd_arg)
	{
		exit_with_error("malloc (cmd_arg)", 1);
	}
	cmd_path = parsing(cmd_arg[0], envp);
	if (!cmd_path)
	{
		free_matrix(cmd_arg);
		exit_with_error("command not found", 127);
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
	{
		free_matrix(cmd_arg);
		free(cmd_path);
		exit_with_error("execve", 1);
	}
}

void	child_process(int infile, char *cmd, int *fd, char **envp)
{
	if (dup2(infile, 0) == -1)
		exit_with_error("dup2 (infile)", 1);
	{
		perror("dup2 (infile)");
		exit(1);
	}
	if (dup2(fd[1], 1) == -1)
		exit_with_error("dup2 (pipe write end)", 1);
	close(fd[0]);
	close(infile);
	execute(cmd, envp);
}

void parent_process(int outfile, char *cmd, int *fd, char **envp)
{
	if (dup2(outfile, 1) == -1)
		exit_with_error("dup2 (outfile)", 1);
	if (dup2(fd[0], 0) == -1)
		exit_with_error("dup2 (pipe read end)", 1);
	close(fd[1]);
	close(outfile);
	execute(cmd, envp);
}

void	pipex(int infile, int outfile, char *cmd1, char *cmd2, char **envp)
{
	int	fd[2];
	pid_t	process_id;

	if (pipe(fd) == -1)
		exit_with_error("pipe", 1);
	process_id = fork();
	if (process_id == -1)
		exit_with_error("fork", 1);
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
		int outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (infile < 0 || outfile < 0)
			exit_with_error("open file", 1);		
		if (!spaces_check(argv[2]) || !spaces_check(argv[3]))
				exit_with_error("command is empty", 1);
		pipex(infile, outfile, argv[2], argv[3], envp);
	}
	else
		exit_with_error("wrong number of arguments", 2);
	return (0);
}
