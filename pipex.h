/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:15:04 by asergina          #+#    #+#             */
/*   Updated: 2025/09/06 18:46:53 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>

void	pipex(char **argv, char **envp);
void	p_p(int in, int out, char *cmd2, pid_t pid1, int *fd, char **env);
void	child_cmd2(int outfile, char *cmd, int *fd, char **envp, int infile);
void	child_cmd1(int infile, char *cmd, int *fd, char **envp, int outfile);
void	execute(char *cmd, char **envp);
char	*parsing(char *cmd, char **envp);
char	*free_return(char **to_free, char *to_return);
void	free_matrix(char **matrix);
int		spaces_check(char *cmd);
void	exit_with_error(const char *msg, int code);

#endif