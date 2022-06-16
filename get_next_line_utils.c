/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes < vlopes@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:45:05 by vlopes            #+#    #+#             */
/*   Updated: 2022/06/15 18:38:30 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;
	char	o;

	p = (char *)s;
	i = 0;
	o = (char)c;
	while (p[i] != 0)
	{
		if (p[i] != 0)
			return (p + i);
		i++;
	}
	if (p[i] == 0 && o == 0)
		return (p + i);
	return (0);
}	

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != 0)
	{
		s++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	u;
	char	*ab;

	ab = (char *)src;
	n = 0;
	u = ft_strlen(ab);
	if (!dst)
		return (0);
	if (!dstsize)
		return (u);
	while (ab[n] && n < dstsize - 1)
	{
		dst[n] = ab[n];
		n++;
	}
	dst[n] = 0;
	return (u);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*name;

	i = 0;
	if (s1 == NULL)
		return (0);
	name = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!name)
		return (0);
	while (*s1 != 0)
	{
		name[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != 0)
	{
		name[i] = *s2;
		i++;
		s2++;
	}
	name[i] = 0;
	return (name);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*name;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	name = malloc((len + 1) * sizeof(char));
	if (!name)
		return (0);
	ft_strlcpy (name, s + start, len + 1);
	return (name);
}
