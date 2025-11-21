/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/11/21 21:35:06 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	fd[2];
}				t_fd;

int		pipex(char **argv, char **envp);
void	execute(char *cmd, char **envp);
void	exit_with_error(const char *msg, int code);

#endif
