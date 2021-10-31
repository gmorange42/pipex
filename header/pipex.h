/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:28:03 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/18 13:37:41 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>
# include <sys/wait.h>

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_all
{
	int		is_there_infile;
	int		here_doc;
	char	*limiter;
	int		fd_infile;
	int		fd_temp;
	int		fd_outfile;
	int		nbr_cmd;
	int		*pid;
	int		nbr_pid;
	int		**pipefd;
	int		nbr_pipe;
	char	***cmd;
	char	**path;
	int		ret;
}				t_all;

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		check_file(char *file);
void	check_infile(t_all *all, char *infile);
void	check_outfile(t_all *all, char *outfile);
void	stock_path(t_all *all, char **envp);
void	destroy_all(t_all *all);
void	free_tab_path(t_all *all);
void	free_tab_cmd(t_all *all);
int		is_it_cmd(t_all *all, char *cmd, int index);
void	check_and_stock_cmds(t_all *all, int ac, char **av);
void	creat_pipes(t_all *all, int i);
void	malloc_pipefd_pid(t_all *all);
void	init(t_all *all, int ac);
void	first_cmd(t_all *all, char **envp);
void	middle_cmd(t_all *all, char **envp, int i);
void	last_cmd(t_all *all, char **envp);
void	pipe_all(t_all *all, char **envp);
void	check_mode(t_all *all, int ac, char **av);
void	get_line(t_all *all);

#endif
