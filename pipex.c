/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/09/06 18:46:53 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "libft/libft.h"

void	pipex(char **argv, char **envp)
{
	int 	infile;
	int     outfile;
	int	fd[2];
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

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		if (!spaces_check(argv[2]) || !spaces_check(argv[3]))
			exit_with_error("command is empty", 0);
		pipex(argv, envp);
	}
	else
		exit_with_error("wrong number of arguments", 2);
	return (0);
}
