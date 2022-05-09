/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:18:18 by atouba            #+#    #+#             */
/*   Updated: 2021/12/13 20:44:17 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = 0;
	}
}

char	*after_back_slach_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n' && s[i + 1])
		return (s + i + 1);
	if (s[i] == '\n' && s[i + 1] == '\0')
		return (s + i);
	return (0);
}

int	ft_strlen(char *s, int choice)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\n' && choice == 0 && s[i])
		i++;
	while (choice == 1 && s[i])
		i++;
	return (i + 1);
}

char	*ft_strdup(char *s)
{
	char	*ans;
	int		i;

	i = 0;
	if (!s)
		return (0);
	ans = malloc(sizeof(char) * (ft_strlen(s, 1) + 1));
	if (!ans)
		return (0);
	while (s[i])
	{
		ans[i] = s[i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
