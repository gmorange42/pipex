/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:31:21 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/18 16:32:03 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	first_cmd(t_all *all, char **envp)
{
	creat_pipes(all, 0);
	all->pid[0] = fork();
	if (all->pid[0] == -1)
		destroy_all(all);
	else if (all->pid[0] == 0)
	{
		if (all->here_doc == 0)
		{
			dup2(all->fd_infile, 0);
			close(all->fd_infile);
		}
		else
		{
			dup2(all->fd_temp, 0);
			close(all->fd_temp);
		}
		dup2(all->pipefd[0][1], 1);
		close(all->pipefd[0][1]);
		close(all->pipefd[0][0]);
		execve(all->cmd[0][0], all->cmd[0], envp);
		destroy_all(all);
	}
}

void	middle_cmd(t_all *all, char **envp, int i)
{
	if (all->pid[i - 1] != 0)
	{
		creat_pipes(all, i);
		all->pid[i] = fork();
		if (all->pid[i] == -1)
			destroy_all(all);
		else if (all->pid[i] != 0)
		{
			close(all->pipefd[i - 1][0]);
			close(all->pipefd[i - 1][1]);
		}
		else if (all->pid[i] == 0)
		{
			dup2(all->pipefd[i - 1][0], 0);
			close(all->pipefd[i - 1][0]);
			dup2(all->pipefd[i][1], 1);
			close(all->pipefd[i][1]);
			close(all->pipefd[i - 1][1]);
			close(all->pipefd[i][0]);
			execve(all->cmd[i][0], all->cmd[i], envp);
			destroy_all(all);
		}
	}
}

void	last_cmd(t_all *all, char **envp)
{
	if (all->pid[all->nbr_pid - 2] != 0)
	{
		all->pid[all->nbr_cmd - 1] = fork();
		if (all->pid[all->nbr_cmd - 1] == -1)
			destroy_all(all);
		else if (all->pid[all->nbr_cmd - 1] != 0)
		{
			close(all->pipefd[all->nbr_pipe - 1][0]);
			close(all->pipefd[all->nbr_pipe - 1][1]);
		}
		else if (all->pid[all->nbr_cmd - 1] == 0)
		{
			dup2(all->pipefd[all->nbr_pipe - 1][0], 0);
			close(all->pipefd[all->nbr_pipe - 1][0]);
			dup2(all->fd_outfile, 1);
			close(all->fd_outfile);
			close(all->pipefd[all->nbr_pipe - 1][1]);
			execve(all->cmd[all->nbr_cmd - 1][0], all->cmd[all->nbr_cmd - 1] \
					, envp);
			destroy_all(all);
		}
	}
}

void	pipe_all(t_all *all, char **envp)
{
	int	i;
	int	status;

	status = 1;
	i = 1;
	malloc_pipefd_pid(all);
	first_cmd(all, envp);
	while (i < all->nbr_cmd - 1)
		middle_cmd(all, envp, i++);
	last_cmd(all, envp);
	i = 0;
	while (i < all->nbr_cmd)
		waitpid(all->pid[i++], (&status), 0);
	if (status != 0)
	{
		if (all->ret == 0)
			all->ret = 1;
	}
	else
		all->ret = 0;
}
