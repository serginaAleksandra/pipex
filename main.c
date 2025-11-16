/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/11/16 22:43:44 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// void	exit_with_error(const char *msg, int code)
// {
// 	if (errno)
// 		perror(msg);
// 	else
// 		ft_printf("Error: %s\n", msg);
// 	exit(code);
// }

void	exit_with_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

static int	spaces_check(char *cmd)
{
	if (!*cmd)
		return (0);
	while (*cmd)
	{
		if (*cmd != ' ' && *cmd != '\t')
			return (1);
		cmd++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;

	status = 0;
	if (argc == 5)
	{
		if (!spaces_check(argv[2]) || !spaces_check(argv[3]))
			exit_with_error("command is empty");
			//exit_with_error("command is empty", 1);
		pipex(argv, envp);
	}
	else
		exit_with_error("wrong number of arguments");
		//exit_with_error("wrong number of arguments", 2);
	return (WEXITSTATUS(status));
}
