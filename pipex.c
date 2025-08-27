/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/08/11 19:40:23 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

char	*parsing(char *cmd, char **envp)
{
	int	i
	char	*path_envp;
	char	**pathes;
	char	*path;
	char	*cmd_path;

	i = 0;
	while (envp[i])
	{
		path_envp = ft_strnstr(envp[i], "PATH=", 5);
		if(path_envp != NULL)
			break;
		i++;
	}
	pathes = ft_split(PATH_envp, ":");
	i = 0;
	while(pathes[i])
	{
		path = ft_strjoin(pathes[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (acess(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path); // ?
		i++;
	}
	return (NULL); //wrong command from argv
}

void	execute(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_argv;

	cmd_argv = ft_split(cmd, ' ');
	cmd_path = parsing(cmd_argv[0], envp);
	if (!cmd_path)
	{
		perror("command not found");
		exit(127);
	}
	exceve(cmd_path, cmd_argv, envp);
}

void	pipex()
{
	int	fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return;
	if (pid == 0)
		//child process
	else
		//parent process
}

int	main(int argc, char *argv[], char **envp)
{
	if (argc == 5)
	{
		int infile = open(argv[1], O_RDONLY);
		int outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644 );
		if (infile < 0 || outfile < 0)
			return (-1);
		
		
	}
	else 
		return (write(1, "Error\n", 6), return (0));
	return (0);
}
