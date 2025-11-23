/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/11/23 00:37:55 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>

static void	init_pipeline(t_pipeline *pl, int argc, char **argv)
{
    pl->cmd_count = argc - 3;
    pl->infile = open(argv[1], O_RDONLY);
    if (pl->infile == -1)
        perror(argv[1]);
    pl->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (pl->outfile == -1)
        perror(argv[argc - 1]);
    pl->pids = malloc(sizeof(pid_t) * pl->cmd_count);
    if (!pl->pids)
        exit_with_error("malloc (pids)", EXIT_FAILURE);
    pl->prev_fd = -1;
}

static void	open_stage_pipe(t_pipeline *pl, int is_last)
{
    if (is_last)
    {
        pl->pipe_fd[0] = -1;
        pl->pipe_fd[1] = -1;
        return ;
    }
    if (pipe(pl->pipe_fd) == -1)
        exit_with_error("pipe", EXIT_FAILURE);
}

static void	update_parent_state(t_pipeline *pl, int is_last)
{
    close_if_valid(pl->prev_fd);
    if (is_last)
    {
        close_if_valid(pl->pipe_fd[0]);
        pl->prev_fd = -1;
        return ;
    }
    close_if_valid(pl->pipe_fd[1]);
    pl->prev_fd = pl->pipe_fd[0];
}

static void	run_pipeline(t_pipeline *pl, char **argv, char **envp)
{
    int	i;
    int	is_last;

    i = 0;
    while (i < pl->cmd_count)
    {
        is_last = (i == pl->cmd_count - 1);
        open_stage_pipe(pl, is_last);
        pl->pids[i] = fork();
        if (pl->pids[i] == -1)
            exit_with_error("fork", EXIT_FAILURE);
        if (pl->pids[i] == 0)
            child_process(pl, i, argv, envp);
        update_parent_state(pl, is_last);
        i++;
    }
    close_if_valid(pl->prev_fd);
    close_if_valid(pl->infile);
    close_if_valid(pl->outfile);
}

int	pipex(int argc, char **argv, char **envp)
{
    t_pipeline	pl;
    int			exit_status;

    init_pipeline(&pl, argc, argv);
    run_pipeline(&pl, argv, envp);
    exit_status = wait_children(&pl);
    free(pl.pids);
    return (exit_status);
}

