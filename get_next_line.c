/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes < vlopes@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:51:28 by vlopes            #+#    #+#             */
/*   Updated: 2022/06/14 14:03:22 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rec;
	char 		*util;
	char		*other;
	int 		i;
	
	i = 0;
	util = 0;
	rec = "";
	util = malloc(sizeof(char));
	
	while(read(fd, util, BUFFER_SIZE))
	{	
		rec = ft_strjoin(rec, util);
		while (util[i])
		{
			if(util[i] == 10)
				break;
			i++;
		}
	}
	other = ft_substr(util, 0, i + 1);
	free(util);
	return (other);
}
