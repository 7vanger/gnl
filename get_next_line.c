/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes < vlopes@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:51:28 by vlopes            #+#    #+#             */
/*   Updated: 2022/06/19 17:03:11 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fuction(char *rec)
{
	char	*other;
	int 	i;

	other = 0;
	i = 0;
	while (rec[i] != 0 && rec[i] != 10)
		i++;
	if (rec[i] == 10)
		other = ft_substr(rec, 0, i + 1);
	else
		other = ft_substr(rec, 0, i);
	return (other);
}

char	*ft_cut(char *rec)
{
	char	*cut;
	int 	i;
	int		j;

	j = ft_strlen(rec);
	i = 0;
	while (rec[i] != 10)
		i++;
	if (rec[i] == 10)
		i++;
	cut = ft_substr(rec, 0, j - i);
	return (cut);
}

char	*get_next_line(int fd)
{
	static char	*rec;
	char 		*util;
	char		*other;
	int 		i;
	
	i = 1;
	rec = "";
	other = 0;
	util = malloc(BUFFER_SIZE + 1);
	if (!util)
		return (0);
	while(!ft_strchr(rec, 10) && i > 0)
	{
		i = read(fd, util, BUFFER_SIZE);
		if (i < 0)
			return (0);
		rec = ft_strjoin(rec, util);
	}
	other = ft_fuction(rec);
	rec = ft_cut(rec);
	free(util);
	return (other);
}
