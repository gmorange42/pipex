/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:46:05 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/12 11:26:20 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (cs1[i] || cs2[i])
	{
		if ((cs1[i] != cs2[i]) || cs1[i] == '\0' || cs2[i] == '\0')
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (i != n)
	{
		if ((cs1[i] != cs2[i]) || cs1[i] == '\0' || cs2[i] == '\0')
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen(s1);
	dup = malloc((sizeof(char) * len) + 1);
	if (dup == 0)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))) + 1);
	if (str == 0)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
