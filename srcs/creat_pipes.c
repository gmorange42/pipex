/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:27:05 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/18 14:29:32 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	creat_pipes(t_all *all, int i)
{
	if (pipe(all->pipefd[i]) == -1)
		destroy_all(all);
}

void	malloc_pipefd_pid(t_all *all)
{
	int	i;

	i = 0;
	all->pipefd = malloc(sizeof(int *) * all->nbr_pipe);
	if (all->pipefd == NULL)
		destroy_all(all);
	while (i < all->nbr_pipe)
	{
		all->pipefd[i] = malloc(sizeof(int) * 2);
		if (all->pipefd[i] == NULL)
			destroy_all(all);
		i++;
	}
	all->pid = malloc(sizeof(int) * all->nbr_pid);
	if (all->pid == NULL)
		destroy_all(all);
}
