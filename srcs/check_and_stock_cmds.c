/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_stock_cmds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:07:30 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/18 16:40:26 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	add_slash(t_all *all, char *cmd, char **slash_cmd)
{
	int	i;

	i = 0;
	(*slash_cmd) = malloc(sizeof(char) * (ft_strlen(cmd) + 2));
	if ((*slash_cmd) == NULL)
	{
		free_tab_path(all);
		exit(0);
	}
	(*slash_cmd)[0] = '/';
	while (cmd[i])
	{
		(*slash_cmd)[i + 1] = cmd[i];
		i++;
	}
	(*slash_cmd)[i + 1] = 0;
}

void	loop_to_test(t_all *all, char **slash_cmd, int *ret, int index)
{
	int		i;
	char	*str_path_cmd;

	i = 0;
	str_path_cmd = NULL;
	while (all->path[i] && (*ret) == -1)
	{
		str_path_cmd = ft_strjoin(all->path[i], (*slash_cmd));
		if (check_file(str_path_cmd) >= 0)
		{
			free(all->cmd[index][0]);
			all->cmd[index][0] = NULL;
			all->cmd[index][0] = ft_strdup(str_path_cmd);
			(*ret) = 1;
		}
		free(str_path_cmd);
		str_path_cmd = NULL;
		i++;
	}
}

int	is_it_cmd(t_all *all, char *cmd, int index)
{
	int		ret;
	char	*slash_cmd;

	ret = -1;
	slash_cmd = NULL;
	all->cmd[index] = ft_split(cmd, ' ');
	if (check_file(all->cmd[index][0]) >= 0)
		ret = 1;
	else
	{
		add_slash(all, *(all->cmd)[index], &slash_cmd);
		loop_to_test(all, &slash_cmd, &ret, index);
	}
	free(slash_cmd);
	slash_cmd = NULL;
	return (ret);
}

void	set_tab_cmd(t_all *all, int ac)
{
	int	i;

	i = 0;
	all->cmd = malloc(sizeof(char **) * (ac - 2));
	while (i < ac - 2)
	{
		all->cmd[i] = NULL;
		i++;
	}
}

void	check_and_stock_cmds(t_all *all, int ac, char **av)
{
	int	i;
	int	h;

	if (all->here_doc == 1)
		i = 3;
	else
		i = 2;
	h = i;
	set_tab_cmd(all, ac);
	while (i < ac - 1)
	{
		if (av[i][0] == 0)
		{
			ft_putstr("empty string in argument\n");
			destroy_all(all);
		}
		if (is_it_cmd(all, av[i], i - h) == -1)
		{
			ft_putstr("command not found: ");
			ft_putstr(av[i]);
			ft_putstr("\n");
			all->ret = 127;
		}
		i++;
	}
}
