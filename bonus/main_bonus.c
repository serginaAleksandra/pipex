/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/11/23 00:36:49 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include <errno.h>

void	close_if_valid(int fd)
{
    if (fd != -1)
        close(fd);
}

void	exit_with_error(const char *msg, int code)
{
	if (errno)
		perror(msg);
	else
		ft_printf("Error: %s\n", msg);
	exit(code);
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
	int	i;

	if (argc < 5)
		exit_with_error("wrong number of arguments", 2);
	i = 2;
	while (i < argc - 1)
	{
		if (!spaces_check(argv[i]))
			exit_with_error("command is empty", 1);
		i++;
	}
	return (pipex(argc, argv, envp));
}
