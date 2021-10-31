/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:58:46 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/12 11:26:02 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	stock_path(t_all *all, char **envp)
{
	int		i;
	char	*str_path;

	i = 0;
	str_path = NULL;
	while (envp[i] != NULL && ft_strncmp((const char *)envp[i], "PATH", 4) != 0)
		i++;
	if (envp[i] == NULL)
	{
		ft_putstr("PATH not found\n");
		exit(0);
	}
	str_path = ft_strdup(&envp[i][5]);
	if (str_path == NULL)
	{
		ft_putstr("ft_strdup() failed\n");
		exit(0);
	}
	all->path = ft_split(str_path, ':');
	free(str_path);
	str_path = NULL;
}
