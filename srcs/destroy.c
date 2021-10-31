/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:03:47 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/18 15:39:54 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	free_tab_path(t_all *all)
{
	int	i;

	i = 0;
	while (all->path[i])
	{
		free(all->path[i]);
		all->path[i] = NULL;
		i++;
	}
	free(all->path);
	all->path = NULL;
}

void	free_tab_cmd(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	if (all->cmd != NULL)
	{
		while (all->cmd[i])
		{
			j = 0;
			while (all->cmd[i][j])
			{
				free(all->cmd[i][j]);
				all->cmd[i][j] = NULL;
				j++;
			}
			free(all->cmd[i]);
			all->cmd[i] = NULL;
			i++;
		}
		free(all->cmd);
		all->cmd = NULL;
	}
}

void	free_pipefd_pid(t_all *all)
{
	int	i;

	i = 0;
	if (all->pipefd != NULL)
	{
		while (i < all->nbr_pipe && all->pipefd[i] != NULL)
		{
			free(all->pipefd[i]);
			all->pipefd[i] = NULL;
			i++;
		}
		free(all->pipefd);
		all->pipefd = NULL;
		free(all->pid);
		all->pid = NULL;
	}
}

void	destroy_all(t_all *all)
{
	free_tab_path(all);
	free_tab_cmd(all);
	free_pipefd_pid(all);
	if (all->here_doc == 1)
	{
		free(all->limiter);
		all->limiter = NULL;
		unlink("/tmp/temp");
	}
	else if (all->is_there_infile == 1)
		close(all->fd_infile);
	close(all->fd_outfile);
	exit(all->ret);
}
