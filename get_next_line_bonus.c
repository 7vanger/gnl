/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes < vlopes@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:05:06 by vlopes            #+#    #+#             */
/*   Updated: 2022/06/21 18:23:27 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_fuction(char *rec)
{
	char	*other;
	int		i;

	i = 0;
	if (!rec[i])
		return (0);
	while (rec[i] && rec[i] != 10)
		i++;
	other = malloc((i + 2) * sizeof(char));
	if (!other)
		return (0);
	i = 0;
	while (rec[i] && rec[i] != 10)
	{
		other[i] = rec[i];
		i++;
	}
	if (rec[i] == 10)
		other[i++] = 10;
	other[i] = 0;
	return (other);
}

static char	*ft_cut(char *rec)
{
	char	*cut;
	int		i;
	int		m;

	i = 0;
	while (rec[i] != 10 && rec[i])
		i++;
	if (!rec[i])
	{
		free(rec);
		return (0);
	}
	m = 0;
	cut = malloc((ft_strlen(rec) - i + 1) * sizeof(char));
	if (!cut)
		return (0);
	i++;
	while (rec[i])
		cut[m++] = rec[i++];
	cut[m] = 0;
	free(rec);
	return (cut);
}

static char	*rec_function(int fd, char *rec)
{
	char	*util;
	int		i;

	i = 1;
	util = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!util)
		return (0);
	while (!ft_strchr(rec, 10) && i != 0)
	{
		i = read(fd, util, BUFFER_SIZE);
		if (i < 0)
		{
			free(util);
			return (0);
		}
		util[i] = 0;
		if (!rec)
		{
			rec = malloc(1 * sizeof(char));
			*rec = 0;
		}
		rec = ft_strjoin(rec, util);
	}
	free(util);
	return (rec);
}

char	*get_next_line(int fd)
{
	static char	*rec[4096];
	char		*other;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	rec[fd] = rec_function(fd, rec[fd]);
	if (!rec[fd])
		return (0);
	other = ft_fuction(rec[fd]);
	rec[fd] = ft_cut(rec[fd]);
	return (other);
}
