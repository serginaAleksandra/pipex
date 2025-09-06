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

void	exit_with_error(const char *msg, int code)
{
	perror(msg);
	exit(code);
}

int	spaces_check(char *cmd)
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