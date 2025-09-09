/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/09/06 18:46:53 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>

void	child_cmd1(int infile, char *cmd, int *fd, char **envp, int outfile)
{
	close(fd[0]);
	close(outfile);
	if (dup2(infile, 0) == -1)
		exit_with_error("dup2 (infile)", 1);
	if (dup2(fd[1], 1) == -1)
		exit_with_error("dup2 (pipe write end)", 1);
	close(fd[1]);
	close(infile);
	execute(cmd, envp);
}

void	child_cmd2(int outfile, char *cmd, int *fd, char **envp, int infile)
{
	close(fd[1]);
	close(infile);
	if (dup2(outfile, 1) == -1)
		exit_with_error("dup2 (outfile)", 1);
	if (dup2(fd[0], 0) == -1)
		exit_with_error("dup2 (pipe read end)", 1);
	close(fd[0]);
	close(outfile);
	execute(cmd, envp);
}

void	p_p(int in, int out, char *cmd2, pid_t pid1, int *fd, char **env)
{
	int		status;
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
		exit_with_error("fork", 1);
	if (pid2 == 0)
		child_cmd2(out, cmd2, fd, env, in);
	else
	{
		close(fd[0]);
		close(fd[1]);
		close(in);
		close(out);
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
	}
}

void	pipex(char **argv, char **envp)
{
	int 	infile;
	int     outfile;
	int		fd[2];
	pid_t	pid1;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		exit_with_error("open infile", 1); 
	outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile == -1)
	{
		close(infile);
		exit_with_error("open outfile", 1);
	}
	if (pipe(fd) == -1)
		exit_with_error("pipe", 1);
	pid1 = fork();
	if (pid1 == -1)
		exit_with_error("fork", 1);
	if (pid1 == 0)
		child_cmd1(infile, argv[2], fd, envp, outfile);
	else
		p_p(infile, outfile, argv[3], pid1, fd, envp);
}