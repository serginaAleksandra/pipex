/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
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

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	*free_return(char **to_free, char *to_return)
{
	free_matrix(to_free);
	return (to_return);
}

char	*parsing(char *cmd, char **envp)
{
	int	i;
	char	**envp_path;
	char	*path;
	char	*cmd_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i] || !(envp_path = ft_split(envp[i] + 5, ':')))
		return (NULL);
	i = 0;
	while(envp_path[i])
	{
		if (!(path = ft_strjoin(envp_path[i], "/")))
			return (free_return(envp_path, NULL));
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (!cmd_path)
   			return (free_return(envp_path, NULL));
		if (access(cmd_path, X_OK) == 0)
			return (free_return(envp_path, cmd_path));
		free(cmd_path);
		i++;
	}
	return (free_return(envp_path, NULL));
}

void	execute(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	if (!cmd_arg)
	{
		exit_with_error("malloc (cmd_arg)", 1);
	}
	cmd_path = parsing(cmd_arg[0], envp);
	if (!cmd_path)
	{
		free_matrix(cmd_arg);
		exit_with_error("command not found", 127);
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
	{
		free_matrix(cmd_arg);
		free(cmd_path);
		exit_with_error("execve", 1);
	}
}