/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:25:27 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/12 11:24:59 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init(t_all *all, int ac)
{
	all->is_there_infile = 1;
	all->cmd = 0;
	all->pipefd = 0;
	all->here_doc = 0;
	all->fd_infile = -1;
	all->fd_outfile = -1;
	all->nbr_cmd = ac - 3;
	all->nbr_pipe = all->nbr_cmd - 1;
	all->nbr_pid = all->nbr_cmd;
	all->path = NULL;
	all->ret = 0;
}
