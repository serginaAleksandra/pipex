/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/11/21 21:36:21 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>

static void	child_cmd1(t_fd *fds, char *cmd, char **env)
{
	close(fds->fd[0]);
	if (fds->outfile != -1)
		close(fds->outfile);
	if (fds->infile == -1)
	{
		close(fds->fd[1]);
		exit(EXIT_FAILURE);
	}
	if (dup2(fds->infile, 0) == -1)
		exit_with_error("dup2 (infile)", EXIT_FAILURE);
	if (dup2(fds->fd[1], 1) == -1)
		exit_with_error("dup2 (pipe write end)", EXIT_FAILURE);
	close(fds->fd[1]);
	close(fds->infile);
	execute(cmd, env);
}

static void	child_cmd2(t_fd *fds, char *cmd, char **env)
{
	close(fds->fd[1]);
	if (fds->infile != -1)
		close(fds->infile);
	if (fds->outfile == -1)
	{
		close(fds->fd[0]);
		exit(EXIT_FAILURE);
	}
	if (dup2(fds->outfile, 1) == -1)
		exit_with_error("dup2 (outfile)", EXIT_FAILURE);
	if (dup2(fds->fd[0], 0) == -1)
		exit_with_error("dup2 (pipe read end)", EXIT_FAILURE);
	close(fds->fd[0]);
	close(fds->outfile);
	execute(cmd, env);
}

static int	parent_process(t_fd *fds, char *cmd2, pid_t pid1, char **env)
{
	int		status1;
	int		status2;
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
		exit_with_error("fork", EXIT_FAILURE);
	if (pid2 == 0)
		child_cmd2(fds, cmd2, env);
	close(fds->fd[0]);
	close(fds->fd[1]);
	if (fds->infile != -1)
		close(fds->infile);
	if (fds->outfile != -1)
		close(fds->outfile);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	if (WIFSIGNALED(status2))
		return (128 + WTERMSIG(status2));
	return (1);
}

int	pipex(char **argv, char **envp)
{
	t_fd	fds;
	pid_t	pid1;

	fds.infile = open(argv[1], O_RDONLY);
	if (fds.infile == -1)
		perror(argv[1]);
	fds.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fds.outfile == -1)
		perror(argv[4]);
	if (pipe(fds.fd) == -1)
		exit_with_error("pipe", EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		exit_with_error("fork", EXIT_FAILURE);
	if (pid1 == 0)
		child_cmd1(&fds, argv[2], envp);
	return (parent_process(&fds, argv[3], pid1, envp));
}
