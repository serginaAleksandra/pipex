/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/11/23 01:12:24 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipeline
{
    int		cmd_count;
    int		infile;
    int		outfile;
    int		prev_fd;
    int		pipe_fd[2];
    pid_t	*pids;
}				t_pipeline;

int		pipex(int argc, char **argv, char **envp);
void	execute(char *cmd, char **envp);
void	exit_with_error(const char *msg, int code);
void	child_process(t_pipeline *pl, int idx, char **argv, char **envp);
int		wait_children(t_pipeline *pl);
void	close_if_valid(int fd);

#endif
