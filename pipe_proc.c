/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/11/21 19:38:28 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>

static void	child_cmd1(t_fd *fds, char *cmd, char **env)
{
	close(fds->fd[0]);
	//close(fds->outfile);
	if (fds->outfile != -1)
		close(fds->outfile);
	if (fds->infile == -1)
	{
		close(fds->fd[1]);
		exit(EXIT_FAILURE);
	}
	if (dup2(fds->infile, 0) == -1)
		exit_with_error("dup2 (infile)");
		//exit_with_error("dup2 (infile)", 1);
	if (dup2(fds->fd[1], 1) == -1)
		exit_with_error("dup2 (pipe write end)");
		//exit_with_error("dup2 (pipe write end)", 1);
	close(fds->fd[1]);
	close(fds->infile);
	execute(cmd, env);
}

static void	child_cmd2(t_fd *fds, char *cmd, char **env)
{
	close(fds->fd[1]);
	//close(fds->infile);
	if (fds->infile != -1)
		close(fds->infile);
	if (fds->outfile == -1)
	{
		close(fds->fd[0]);
		exit(EXIT_FAILURE);
	}
	if (dup2(fds->outfile, 1) == -1)
		exit_with_error("dup2 (outfile)");
		//exit_with_error("dup2 (outfile)", 1);
	if (dup2(fds->fd[0], 0) == -1)
		exit_with_error("dup2 (pipe read end)");
		//exit_with_error("dup2 (pipe read end)", 1);
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
		exit_with_error("fork");
		//exit_with_error("fork", 1);
	if (pid2 == 0)
		child_cmd2(fds, cmd2, env);
	// else
	// {
	// 	close(fds->fd[0]);
	// 	close(fds->fd[1]);
	// 	close(fds->infile);
	// 	close(fds->outfile);
	// 	waitpid(pid1, &status, 0);
	// 	waitpid(pid2, &status, 0);
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
		//exit_with_error("open infile");
		//exit_with_error("open outfile", 1); 
	fds.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fds.outfile == -1)
		perror(argv[4]);
	// {
	// 	close(fds.infile);
	// 	exit_with_error("open outfile");
	// 	//exit_with_error("open outfile", 1);
	// }
	if (pipe(fds.fd) == -1)
		exit_with_error("pipe");
		//exit_with_error("pipe", 1);
	pid1 = fork();
	if (pid1 == -1)
		exit_with_error("fork");
		//exit_with_error("fork", 1);
	if (pid1 == 0)
		child_cmd1(&fds, argv[2], envp);
	// else
	// 	parent_process(&fds, argv[3],pid1, envp);
	return (parent_process(&fds, argv[3],pid1, envp));
}
