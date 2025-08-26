/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/08/26 18:53:27 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	pipex()
{
	int	fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		return ;
	pid1 = fork();
	if (pid1 == -1)
		return ;
	if (pid1 == 0)
	{
		//child process
		
	}
	
}

char	*parsing()
{
	
}

int	main(int argc, char *argv[])
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
