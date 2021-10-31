/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:52:05 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/18 16:31:50 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	check_file(char *file)
{
	int		fd;
	char	test[2];

	fd = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-2);
	if (read(fd, test, 0) < 0)
		return (-3);
	return (fd);
}

void	check_infile(t_all *all, char *infile)
{
	all->fd_infile = check_file(infile);
	if (all->fd_infile == -2 || all->fd_infile == -3)
	{
		ft_putstr(infile);
		if (all->fd_infile == -2)
			ft_putstr(" : file doesn't exist.\n");
		if (all->fd_infile == -3)
			ft_putstr(" is a directory.\n");
		all->is_there_infile = 0;
	}
}

void	check_outfile(t_all *all, char *outfile)
{
	if (all->here_doc == 0)
		all->fd_outfile = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 00644);
	else
		all->fd_outfile = open(outfile, O_RDWR | O_CREAT | O_APPEND, 00644);
	if (all->fd_outfile == -1)
	{
		ft_putstr(outfile);
		ft_putstr(" is a directory.\n");
		all->ret = 1;
		destroy_all(all);
	}
	if (all->is_there_infile == 0)
		destroy_all(all);
}
