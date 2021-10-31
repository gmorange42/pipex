/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:41:50 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/12 11:24:45 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static void	ft_freetab(char **tab, int n)
{
	while (n >= 0)
	{
		free(tab[n]);
		n--;
	}
	free(tab);
}

static char	*ft_strcdup(const char *s, char c)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	i = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_makestr(const char *s, char c, char **tab)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				i++;
				j++;
			}
			tab[index] = ft_strcdup(&s[i - j], c);
			if (tab[index] == 0)
				return (ft_freetab(tab, index));
			j = 0;
			index++;
		}
		else
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			j++;
		}
		else
			i++;
	}
	tab = malloc(sizeof(char *) * (j + 1));
	if (tab == 0)
		return (NULL);
	ft_makestr(s, c, tab);
	tab[j] = NULL;
	return (tab);
}
