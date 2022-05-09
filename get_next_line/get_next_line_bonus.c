/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:17:45 by atouba            #+#    #+#             */
/*   Updated: 2021/12/13 20:10:05 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*strdup_before_back_slach_n(char *s1)
{
	int		i;
	char	*ans;

	i = 0;
	if (!s1)
		return (0);
	ans = (char *)malloc(ft_strlen(s1, 0) + 1);
	if (!ans)
		return (0);
	while (s1[i] && s1[i] != '\n')
	{
		ans[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		ans[i] = '\n';
		ans[i + 1] = 0;
	}
	else
		ans[i] = 0;
	return (ans);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	ans = malloc(sizeof(char) * (ft_strlen(s1, 1) + ft_strlen(s2, 1) + 1));
	if (!ans)
		return (0);
	while (s1[++i] != '\0')
		ans[i] = s1[i];
	while (s2[j] != '\0')
		ans[i++] = s2[j++];
	ans[i] = '\0';
	if (ft_strcmp(s1, "") == 0)
	{
		free(s1);
		s1 = 0;
	}
	return (ans);
}

int	fill_temp(char **temp, int fd)
{
	char	*ans;
	int		r;
	char	*hold;

	r = 1;
	ans = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (r != 0)
	{
		r = read(fd, ans, BUFFER_SIZE);
		if (r <= 0)
		{
			free(ans);
			return (0);
		}
		ans[r] = 0;
		hold = *temp;
		*temp = ft_strjoin(hold, ans);
		free(hold);
		if (*temp && (ft_strchr(*temp, '\n') || *temp[0] == '\n'))
		{
			free(ans);
			break ;
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*ans;
	char		*hold;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	n = fill_temp(&temp[fd], fd);
	if (!n && !temp[fd])
		return (0);
	ans = strdup_before_back_slach_n(temp[fd]);
	if ((ft_strchr(temp[fd], '\n') || temp[fd][0] == '\n')
		&& temp[fd][ft_strchr(temp[fd], '\n') + 1] != '\0')
	{
		hold = ft_strdup(after_back_slach_n(temp[fd]));
		free(temp[fd]);
		temp[fd] = ft_strdup(hold);
		free(hold);
	}
	else
		ft_free(&temp[fd]);
	if ((n == 0 && ft_strcmp(ans, "") == 0))
		return (0);
	return (ans);
}
