/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes < vlopes@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:51:28 by vlopes            #+#    #+#             */
/*   Updated: 2022/06/16 02:00:40 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fuction(char *rec, char *other)
{	
	int i;

	i = 0;
	while (rec[i] != 0 && rec[i] != 10)
		i++;
	if (rec[++i] == 10)
		ft_substr(other, 0, i + 1);
	else
		ft_substr(other, 0, i);
	return (other);
}

char	*ft_cut(char *rec, char *cut)
{
	int i;

	i = 0;
	while (rec[i] != 10)
		i++;
	return (cut + i);
}

char	*get_next_line(int fd)
{
	static char	*rec;
	char 		*util;
	char		*other;
	char		*cut;
	int 		i;
	
	i = 0;
	util = 0;
	rec = "";
	other = 0;
	cut = 0;
	util = malloc(BUFFER_SIZE + 1);
	if (!util)
		return (0);
	while(!ft_strchr(rec, 10))
	{
		read(fd, util, BUFFER_SIZE);
		rec = ft_strjoin(rec, util);
	}
	other = ft_fuction(rec, other);
	rec = ft_cut(rec, cut);
	free(util);
	return (other);
}
