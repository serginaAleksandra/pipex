/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:24:09 by asergina          #+#    #+#             */
/*   Updated: 2025/11/22 23:47:37 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

static void	free_matrix(char **matrix)
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

static char	*free_return(char **to_free, char *to_return)
{
	free_matrix(to_free);
	return (to_return);
}

static char	*find_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	exit_with_error("inappropriate environment", EXIT_FAILURE);
	return (NULL);
}

static char	*parsing(char *cmd, char **envp)
{
	char	**envp_path;
	char	*path;
	char	*cmd_path;
	int		i;

	envp_path = ft_split(find_path_env(envp), ':');
	if (!envp_path)
		return (NULL);
	i = 0;
	while (envp_path[i])
	{
		path = ft_strjoin(envp_path[i], "/");
		if (!path)
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
		exit_with_error("malloc (cmd_arg)", EXIT_FAILURE);
	cmd_path = parsing(cmd_arg[0], envp);
	if (!cmd_path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_arg[0], 2);
		free_matrix(cmd_arg);
		exit(127);
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
	{
		free_matrix(cmd_arg);
		free(cmd_path);
		exit_with_error("execve", EXIT_FAILURE);
	}
}
