/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 00:33:34 by aleksandra        #+#    #+#             */
/*   Updated: 2025/11/23 01:12:11 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	connect_stdin(int idx, int prev_fd, int infile)
{
    if (idx == 0)
    {
        if (infile == -1)
            exit(EXIT_FAILURE);
        if (dup2(infile, STDIN_FILENO) == -1)
            exit_with_error("dup2 (infile)", EXIT_FAILURE);
        return ;
    }
    if (dup2(prev_fd, STDIN_FILENO) == -1)
        exit_with_error("dup2 (pipe read)", EXIT_FAILURE);
}
static void	connect_stdout(int idx, int cmd_count, int pipe_write, int outfile)
{
    if (idx == cmd_count - 1)
    {
        if (outfile == -1)
            exit(EXIT_FAILURE);
        if (dup2(outfile, STDOUT_FILENO) == -1)
            exit_with_error("dup2 (outfile)", EXIT_FAILURE);
        return ;
    }
    if (dup2(pipe_write, STDOUT_FILENO) == -1)
        exit_with_error("dup2 (pipe write)", EXIT_FAILURE);
}

void	child_process(t_pipeline *pl, int idx, char **argv, char **envp)
{
    connect_stdin(idx, pl->prev_fd, pl->infile);
    connect_stdout(idx, pl->cmd_count, pl->pipe_fd[1], pl->outfile);
    close_if_valid(pl->prev_fd);
    close_if_valid(pl->pipe_fd[0]);
    close_if_valid(pl->pipe_fd[1]);
    close_if_valid(pl->infile);
    close_if_valid(pl->outfile);
    execute(argv[idx + 2], envp);
}

int	wait_children(t_pipeline *pl)
{
    int	status;
    int	last_status;
    int	i;

    last_status = 0;
    i = 0;
    while (i < pl->cmd_count)
    {
        if (waitpid(pl->pids[i], &status, 0) == -1)
            exit_with_error("waitpid", EXIT_FAILURE);
        if (i == pl->cmd_count - 1)
            last_status = status;
        i++;
    }
    if (WIFEXITED(last_status))
        return (WEXITSTATUS(last_status));
    if (WIFSIGNALED(last_status))
        return (128 + WTERMSIG(last_status));
    return (1);
}
