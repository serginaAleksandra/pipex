/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/11/17 08:08:29 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	exit_with_error(const char *msg)
{
	if (errno)
		perror(msg);
	else
		ft_printf("Error: %s\n", msg);
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
	return (0);
}
