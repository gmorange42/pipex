/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:22:51 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/18 14:25:39 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	get_line(t_all *all)
{
	char	buffer[10];
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	while (ret > 0)
	{
		i = 0;
		while (i < 9)
		{
			buffer[i] = 0;
			i++;
		}
		ret = read(0, buffer, 9);
		buffer[ret] = 0;
		if (ft_strcmp(buffer, all->limiter) != 0)
			write(all->fd_temp, buffer, ft_strlen(buffer));
		else
			ret = 0;
	}
}

void	check_mode(t_all *all, int ac, char **av)
{
	if ((BONUS == 0 && ac != 5) || (BONUS == 1 && ac < 5))
	{
		ft_putstr("bad number of arguments\n");
		exit(1);
	}
	if (BONUS == 1 && ac == 6)
	{
		if (ft_strcmp(av[1], "here_doc") == 0)
		{
			all->here_doc = 1;
			all->limiter = ft_strjoin(av[2], "\n");
			all->fd_temp = open("/tmp/temp", \
					O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
			get_line(all);
			close(all->fd_temp);
			all->fd_temp = open("/tmp/temp", \
					O_RDWR, S_IRWXU);
			all->nbr_cmd = ac - 4;
			all->nbr_pid = all->nbr_cmd;
			all->nbr_pipe--;
		}
	}
}
