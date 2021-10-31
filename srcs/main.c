/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:34:57 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/18 16:37:56 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_all	all;

	init(&all, ac);
	check_mode(&all, ac, av);
	stock_path(&all, envp);
	check_and_stock_cmds(&all, ac, av);
	if (all.here_doc == 0)
		check_infile(&all, av[1]);
	check_outfile(&all, av[ac - 1]);
	pipe_all(&all, envp);
	destroy_all(&all);
	return (0);
}
