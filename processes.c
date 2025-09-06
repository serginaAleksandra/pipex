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

void	child_cmd1(int infile, char *cmd, int *fd, char **envp, int outfile)
{
	close(fd[0]);
	close(outfile);
	if (dup2(infile, 0) == -1)
		exit_with_error("dup2 (infile)", 1);
	if (dup2(fd[1], 1) == -1)
		exit_with_error("dup2 (pipe write end)", 1);
	close(fd[1]);
	close(infile);
	execute(cmd, envp);
}

void	child_cmd2(int outfile, char *cmd, int *fd, char **envp, int infile)
{
	close(fd[1]);
	close(infile);
	if (dup2(outfile, 1) == -1)
		exit_with_error("dup2 (outfile)", 1);
	if (dup2(fd[0], 0) == -1)
		exit_with_error("dup2 (pipe read end)", 1);
	close(fd[0]);
	close(outfile);
	execute(cmd, envp);
}

void	p_p(int in, int out, char *cmd2, pid_t pid1, int *fd, char **env)
{
	int	status;
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
		exit_with_error("fork", 1);
	if (pid2 == 0)
		child_cmd2(out, cmd2, fd, env, in);
	else
	{
		close(fd[0]);
		close(fd[1]);
		close(in);
		close(out);
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
	}
}