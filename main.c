/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/09/06 18:46:53 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	exit_with_error(const char *msg, int code)
{
	if (errno)
		perror(msg);
	else
		ft_printf("Error: %s\n", msg);
	exit(code);
}

int		spaces_check(char *cmd)
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

int		main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		if (!spaces_check(argv[2]) || !spaces_check(argv[3]))
			exit_with_error("command is empty", 1);
		pipex(argv, envp);
	}
	else
		exit_with_error("wrong number of arguments", 2);
	return (0);
}
